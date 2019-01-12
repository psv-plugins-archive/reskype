// reSkype

#include <taihen.h>
#include <vitasdk.h>

void _start() __attribute__ ((weak, alias ("module_start")));

int module_start(SceSize argc, const void *args) {
  tai_module_info_t info;
  info.size = sizeof(info);
  
  taiGetModuleInfo("SceShell", &info);
  
  char buf[0x2D];
  sceClibMemset(buf,0x00,0x2D);
  taiInjectData(info.modid, 0x00, 0x5161EC, buf, 0x2D);
  
  return SCE_KERNEL_START_SUCCESS;
}

int module_stop(SceSize argc, const void *args) {
  return SCE_KERNEL_STOP_SUCCESS;
}
