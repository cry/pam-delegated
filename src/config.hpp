#include <vector>

#include "tl/optional.hpp"

namespace Config
{
    typedef std::string Url_t;
    typedef std::string Option_t;

    typedef struct
    {
        std::vector<Url_t> remotes;
    } Config_t;

    tl::optional<Config_t> parse(int flags, int argc, const char **argv);
} // namespace Config
