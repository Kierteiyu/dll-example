#include "interface.h"
#include <stdlib.h>

// Define the actual plugin structure with your private data
typedef struct IEnginePlugin {
    int number;
    // in the VSynth case, this would include storage for loaded voices, and other stuff
} IEnginePlugin;

// Fixed implementation - need to access the instance, not the type
EXPORT_API int addToHiddenNumber(IEnginePlugin* plugin, int numb) {
    if (!plugin) {
        return -1; // Error handling for null pointer
    }
    plugin->number = plugin->number + numb;
    return plugin->number;
}

// Function to set the hidden number (for testing purposes)
EXPORT_API void setHiddenNumber(IEnginePlugin* plugin, int value) {
    if (plugin) {
        plugin->number = value;
    }
}

// You'll probably also want functions to create/destroy the plugin instance
EXPORT_API IEnginePlugin* createPlugin(void) {
    IEnginePlugin* plugin = (IEnginePlugin*)malloc(sizeof(IEnginePlugin));
    if (plugin) {
        plugin->number = 4;  // Initialize the hidden number
    }
    return plugin;
}

EXPORT_API void destroyPlugin(IEnginePlugin* plugin) {
    if (plugin) {
        free(plugin);
    }
}
