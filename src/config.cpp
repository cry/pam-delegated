#include <iostream>
#include <optional>
#include <ranges>
#include <variant>

#include "config.hpp"
#include "monad.hpp"

namespace Config
{
    std::optional<std::vector<Option_t>> ToOptions(const auto &lines)
    {
        // todo(cry): implement
        return std::nullopt;
    }

    std::optional<Config_t> CreateFromOptions(const std::vector<Option_t> &options)
    {
        // todo(cry): implement
        return std::nullopt;
    }

    // todo(cry): use flags to determine when to log
    std::optional<Config_t> parse(int flags, int argc, const char **argv)
    {
        auto lines = std::ranges::iota_view{0, argc} | std::views::transform([&argv](int i) {
                         return std::string(argv[i]);
                     });

        return ToOptions(lines).and_then(CreateFromOptions);
    }
} // namespace Config
