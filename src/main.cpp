#include "pl/memory/Hook.h"

// 1. Khai báo Hook: Can thiệp vào hàm kiểm tra tay trái của Minecraft Android
PL_TYPE_INSTANCE_HOOK(
    AllowOffhandHook,
    pl::memory::HookPriority::Normal,
    void, // Dùng void để bỏ qua class Item, tránh lỗi thiếu file header
    pl::memory::SymbolView("_ZNK4Item13allowOffhandEv"), 
    bool
) {
    // Ép game luôn ghi nhận vật phẩm này có thể cầm ở tay trái
    return true; 
}

// 2. Kỹ thuật khởi tạo tự động (Static Initializer)
// Khối lệnh này sẽ tự động chạy ngầm ngay khi file .so được nạp vào bộ nhớ game
struct AutoEnableMod {
    AutoEnableMod() {
        // Chính thức kích hoạt Hook
        pl::memory::HookRegistrar<AllowOffhandHook>().hook();
    }
};

// Khởi tạo một biến toàn cục để hệ thống tự động gọi cấu trúc AutoEnableMod ở trên
static AutoEnableMod g_auto_enable;
