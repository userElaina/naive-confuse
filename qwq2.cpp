#define DEBUG

#include "cmdline/cmdline.h"
#include "qwq2.hpp"

int main(int argc, char** argv) {
    std::string version = "v0.2.0";
    std::string footer = "\n  (qwq2";

    footer += "-" + version + "-" + short_os_name() + "64)";

    cmdline::parser a;
    a.set_program_name("qwq2");
    a.footer(footer.c_str());
    a.add<std::string>("input", 'i', "input file", true, "");
    a.add<std::string>("output", 'o', "output file", false, "");
    a.add<std::string>("key", 'k', "key", false, "");
    a.parse_check(argc, argv);

    encode(a.get<std::string>("input"), a.get<std::string>("output"), a.get<std::string>("key"));
}
