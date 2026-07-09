// 1. Dùng đường dẫn thư viện chính xác của template Wodlevi
#include "pl/memory/Hook.h"

// 2. Sử dụng Macro Hook dành riêng cho Preloader
PL_TYPE_INSTANCE_HOOK(
    AllowOffhandHook,
    pl::memory::HookPriority::Normal,
    void, // Bỏ qua class Item để tránh lỗi định nghĩa
    pl::memory::SymbolView("_ZNK4Item13allowOffhandEv"), 
    bool
) {
    return true; // Ép cho phép cầm tay trái
}

// 3. Khởi tạo Hook bằng cấu trúc tĩnh (tự động chạy)
struct AutoRegister {
    AutoRegister() {
        // Gọi hàm đăng ký Hook của Preloader
        pl::memory::HookRegistrar<AllowOffhandHook>().hook();
    }
};

static AutoRegister g_auto_reg;
