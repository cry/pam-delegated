#include <vector>
#include <optional>

namespace Config
{
    typedef std::string url_t;

    typedef struct
    {
        std::vector<url_t> remotes;
    } Config;

    std::optional<Config> parse(int flags, int argc, const char **argv);
} // namespace Config
