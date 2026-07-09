// Đổi ll thành pl
#include "pl/memory/Hook.h" 

// Lưu ý: Nếu template Android của bạn không có sẵn thư mục mc/world/item/Item.h, 
// bạn có thể xóa dòng include Item.h đi để tránh lỗi thiếu file tiếp theo.

// Khai báo Hook theo chuẩn Preloader (Android)
PL_TYPE_INSTANCE_HOOK(
    AllowOffhandHook,
    pl::memory::HookPriority::Normal,
    void, // Dùng 'void' thay vì 'Item' nếu template không hỗ trợ sẵn class Item
    pl::memory::SymbolView("_ZNK4Item13allowOffhandEv"), 
    bool
) {
    return true; // Ép game luôn cho phép cầm trên tay trái
}

// KHỞI TẠO MOD:
// Bạn hãy tìm hàm khởi chạy mặc định của template (thường là ModLoad, OnLoad, hoặc tương tự) 
// và dán dòng lệnh kích hoạt này vào bên trong:
// pl::memory::HookRegistrar<AllowOffhandHook>().hook();
