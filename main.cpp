/******************
* RTLog++ v0.0.3a *
*******************/
#include <cstdlib>
#include <filesystem>
#include "rtLog.hpp"

int main()
{
    RTLog& rtLog = RTLog::get();
    rtLog.runLogger();

    std::system((std::filesystem::path(RTLOG_BIN_DIR) / "sdl3_demo").string().c_str());

    return 0;
}