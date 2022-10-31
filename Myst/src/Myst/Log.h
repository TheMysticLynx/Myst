//
// Created by Kaiden Howard on 10/28/22.
//
#include <memory>
#include "Core.h"
#include <spdlog/spdlog.h>
#ifndef MYST_LOG_H
#define MYST_LOG_H

namespace Myst {
    MYST_API class Log {
    public:
        static void Init();
        inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; };
        inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; };
    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };
}

#define MYST_CORE_TRACE(...) Myst::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define MYST_CORE_INFO(...) Myst::Log::GetCoreLogger()->info(__VA_ARGS__)
#define MYST_CORE_DEBUG(...) Myst::Log::GetCoreLogger()->debug(__VA_ARGS__)
#define MYST_CORE_WARN(...) Myst::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define MYST_CORE_ERROR(...) Myst::Log::GetCoreLogger()->error(__VA_ARGS__)
#define MYST_CORE_FATAL(...) Myst::Log::GetCoreLogger()->fatal(__VA_ARGS__)

#define MYST_CLIENT_TRACE(...) Myst::Log::GetClientLogger()->trace(__VA_ARGS__)
#define MYST_CLIENT_INFO(...) Myst::Log::GetClientLogger()->info(__VA_ARGS__)
#define MYST_CLIENT_DEBUG(...) Myst::Log::GetClientLogger()->debug(__VA_ARGS__)
#define MYST_CLIENT_WARN(...) Myst::Log::GetClientLogger()->warn(__VA_ARGS__)
#define MYST_CLIENT_ERROR(...) Myst::Log::GetClientLogger()->error(__VA_ARGS__)
#define MYST_CLIENT_FATAL(...) Myst::Log::GetClientLogger()->fatal(__VA_ARGS__)


#endif //MYST_LOG_H
