# Doremon-Gadget
BaseObject : Class nguồn chuyên dùng để load ảnh , xử lý những thứ liên quan đén ảnh
CommonFunction : Lưu những struct , nhưng tham số , trị số chung cho cả project
PlayerObject : kế thừa từ BaseObject ( load ảnh ) dùng để xử lý di chuyển ,  load animation cho nhân vật
ThreatObject :  kế thừa từ BaseObject ( load ảnh ) , dùng để xử lý các con chuột rơi từ trên xuống
ItemObject :  kế thừa từ BaseObject ( load ảnh ) , dùng để xử lý các item rơi từ trên xuống
LifeObject :  kế thừa từ BaseObject ( load ảnh ) quản lý mạng sống của nhân vật ( 4 mạng = 4 quả tim xanh )
TextObject : để viết text lên màn hình game ( hiển thị điểm ) 
SettingFps : Xử lý FPS cho game mượt mà hơn 
