#include <iostream>
#include <ranges>
#include <variant>

#include "config.hpp"
#include "tl/optional.hpp"

namespace Config
{
    tl::optional<std::vector<Option_t>> ToOptions(const auto &lines)
    {
        // todo(cry): implement
        return tl::nullopt;
    }

    tl::optional<Config_t> CreateFromOptions(const std::vector<Option_t> &options)
    {
        // todo(cry): implement
        return tl::nullopt;
    }

    // todo(cry): use flags to determine when to log
    tl::optional<Config_t> parse(int flags, int argc, const char **argv)
    {
        auto lines = std::ranges::iota_view{0, argc} | std::views::transform([&argv](int i) {
                         return std::string(argv[i]);
                     });

        return ToOptions(lines)
            .and_then(CreateFromOptions);
    }
} // namespace Config
