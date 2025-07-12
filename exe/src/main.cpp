#include <dynalo/dynalo.hpp>
#include "interface.h"

#include <iostream>

int main() {
    dynalo::library lib("dllexample.dll");

    auto createPlugin = lib.get_function<IEnginePlugin*()>("createPlugin");
    auto destroyPlugin = lib.get_function<void(IEnginePlugin*)>("destroyPlugin");
    auto setHiddenNumber = lib.get_function<int(IEnginePlugin*, int)>("setHiddenNumber");
    auto addToHiddenNumber = lib.get_function<int(IEnginePlugin*, int)>("addToHiddenNumber");

    IEnginePlugin* plugin = createPlugin();

    setHiddenNumber(plugin, 50);

    std::cout << addToHiddenNumber(plugin, 5) << std::endl; // 55
    std::cout << addToHiddenNumber(plugin, 5) << std::endl; // 60
    std::cout << addToHiddenNumber(plugin, 5) << std::endl; // 65
    std::cout << addToHiddenNumber(plugin, 5) << std::endl; // 70

    destroyPlugin(plugin);
}
