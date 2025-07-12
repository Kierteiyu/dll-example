#pragma once

#include <stdint.h>
#include <string.h>

#ifdef _WIN32
#define EXPORT_API __declspec(dllexport)
#else
#define EXPORT_API
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Opaque handle for engine plugin */
typedef struct IEnginePlugin IEnginePlugin;

/* Plugin interface functions */
EXPORT_API IEnginePlugin* createPlugin(void);
EXPORT_API void destroyPlugin(IEnginePlugin* plugin);
EXPORT_API int addToHiddenNumber(IEnginePlugin* plugin, int numb);
EXPORT_API void setHiddenNumber(IEnginePlugin* plugin, int value);

#ifdef __cplusplus
}
#endif
