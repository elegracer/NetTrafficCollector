#include <core/core.h>

#include <chrono>
#include <map>
#include <string>
#include <vector>
#include <iostream>

#include <sys/sysctl.h>
#include <net/route.h>
#include <net/if.h>
// #include <sys/socket.h>
#include <net/if_dl.h>

struct NetTrafficStat {
    std::chrono::time_point<std::chrono::steady_clock, std::chrono::nanoseconds> tp_retrieval;
    int64_t ifi_ibytes = 0; // total number of octets received
    int64_t ifi_obytes = 0; // total number of octets sent
};

using NetTrafficStatMap = std::map<std::string, NetTrafficStat>;

#define PREALLOC_SYSCTL_BUFFER_BYTES 20 * 1024

int main(int argc, const char* argv[]) {

    std::chrono::time_point<std::chrono::steady_clock, std::chrono::nanoseconds> tp_retrieval;
    std::cout << tp_retrieval.time_since_epoch().count() << std::endl;

    tp_retrieval = std::chrono::steady_clock::now();

    for (int i = 0; i < 1000000; ++i) {
        std::cout << i << std::endl;
    }

    decltype(tp_retrieval) tp_second = std::chrono::steady_clock::now();

    const auto duration = (tp_second - tp_retrieval).count();

    std::cout << duration << std::endl;

    const auto duration2 = std::chrono::duration<double>(tp_second - tp_retrieval).count();

    std::cout << duration2 << std::endl;

    return 0;
}
