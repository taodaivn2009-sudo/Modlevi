#include "ll/api/memory/Hook.h"
#include "ll/api/memory/Memory.h"
#include "mc/world/item/Item.h"

// Định nghĩa Hook cho phép cầm đồ tay trái
LL_TYPE_INSTANCE_HOOK(
    AllowOffhandHook,
    ll::memory::HookPriority::Normal,
    Item,
    ll::memory::SymbolView("_ZNK4Item13allowOffhandEv"), 
    bool
) {
    return true; 
}
