#include <iostream>
#include <optional>
#include <ranges>

#include "config.hpp"
#include "monad.hpp"

namespace Config
{
    using namespace Monad;

    OrError<std::vector<std::string>> ToOptions(const auto& line)
    {
        return "unimplemented";
    }

    OrError<Config> CreateFromOptions(const std::vector<std::string>& options)
    {
        return "unimplemented";
    }

    // todo(cry): use flags to determine when to log
    std::optional<Config> parse(int flags, int argc, const char **argv)
    {
        auto lines = std::ranges::iota_view{0, argc} | std::views::transform([&argv](int i) {
                         return std::string(argv[i]);
                     });

        OrError<Config> config = ToOptions(lines) >> CreateFromOptions;
        return std::nullopt;
    }
} // namespace Config
