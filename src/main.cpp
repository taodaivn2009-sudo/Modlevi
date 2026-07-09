#include <ll/api/memory/Hook.h>
#include <ll/api/memory/Memory.h>

// Khai báo Hook: Can thiệp vào hàm kiểm tra tay trái của Minecraft
LL_TYPE_INSTANCE_HOOK(
    AllowOffhandHook,
    ll::memory::HookPriority::Normal,
    void, // Bỏ qua class Item để không bị lỗi thiếu file
    ll::memory::SymbolView("_ZNK4Item13allowOffhandEv"), 
    bool
) {
    // Ép game luôn ghi nhận vật phẩm này có thể cầm ở tay trái
    return true; 
}

// Kỹ thuật khởi tạo tự động (Static Initializer)
// Không cần quan tâm template dùng hàm Load() tên là gì, khối này tự động chạy!
struct AutoEnableMod {
    AutoEnableMod() {
        ll::memory::HookRegistrar<AllowOffhandHook>().hook();
    }
};

static AutoEnableMod g_auto_enable;
