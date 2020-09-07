#include <string>
#include <variant>
#include <functional>

namespace Monad
{
    template <typename T, typename ErrType>
    using Either = std::variant<T, ErrType>;

    typedef std::string Error;

    template <typename T>
    using OrError = Either<T, Error>;

    // OrError<A> -> (A -> OrError<B>) -> OrError<B>
    template <typename AOrError, typename F>
    auto bind(AOrError m, F f)
    {
        using ErrType = std::variant_alternative_t<1, AOrError>;
        using BOrError = std::invoke_result_t<F, std::variant_alternative_t<0, AOrError>>;

        if (std::holds_alternative<ErrType>(m))
        {
            auto error = std::get<ErrType>(m);
            return static_cast<BOrError>(error);
        }
        else
        {
            return std::invoke(f, std::get<0>(m));
        }
    }

    template <typename OptionalM, typename F>
    auto operator>>(OptionalM &&m, F &&f)
    {
        return bind(std::forward<OptionalM>(m),
                    std::forward<F>(f));
    };

} // namespace Monad
