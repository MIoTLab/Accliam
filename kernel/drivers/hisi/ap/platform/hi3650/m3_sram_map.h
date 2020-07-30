#ifndef __M3_SRAM_MAP_H__
#define __M3_SRAM_MAP_H__ 
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif
#if defined(__CMSIS_RTOS)
#include <soc_lpmcu_baseaddr_interface.h>
#include <soc_acpu_baseaddr_interface.h>
#endif
#include <m3_ddr_map.h>
#ifdef __FASTBOOT__
#define M3_SRAM_BASE (LPMCU_FIRMWARE_BACKUP_ADDR)
#else
#define M3_SRAM_BASE (SOC_LPMCU_LP_RAM_BASE_ADDR)
#endif
#define M3_SRAM_SIZE (LPMCU_RAM_SIZE)
#define M3_SRAM_AO_SIZE (0xC000)
#define AON_SYS_BASE (M3_SRAM_BASE)
#define AON_SYS_RESERVED_SIZE (0)
#define AON_SYS_SIZE (0x6E00 - AON_SYS_RESERVED_SIZE)
#define AON_STORAGE_SOCP_BASE (AON_SYS_BASE + AON_SYS_SIZE + AON_SYS_RESERVED_SIZE)
#define AON_STORAGE_SOCP_SIZE (0x800)
#define INIT_PARA_BASE (AON_STORAGE_SOCP_BASE + AON_STORAGE_SOCP_SIZE)
#define INIT_PARA_SIZE (0x100)
#define RUNTIME_VAR_BASE (INIT_PARA_BASE + INIT_PARA_SIZE)
#define RUNTIME_VAR_SIZE (0x100)
#define LPMCU_STAT_BASE (RUNTIME_VAR_BASE + RUNTIME_VAR_SIZE)
#define LPMCU_STAT_SIZE (0x400)
#define DDR_REG_BACKUP_BASE (LPMCU_STAT_BASE + LPMCU_STAT_SIZE)
#define DDR_REG_BACKUP_SIZE (0x80)
#define DDR_TRAINNING_BASE (DDR_REG_BACKUP_BASE + DDR_REG_BACKUP_SIZE)
#define DDR_TRAINNING_SIZE (0x2600)
#define DDR_PROFILE_BASE (DDR_TRAINNING_BASE + DDR_TRAINNING_SIZE)
#define DDR_PROFILE_SIZE (0x380)
#define DDR_POLICY_BASE (DDR_PROFILE_BASE + DDR_PROFILE_SIZE)
#define DDR_POLICY_SIZE (0x80)
#if ((DDR_POLICY_BASE + DDR_POLICY_SIZE - M3_SRAM_BASE) > (M3_SRAM_AO_SIZE))
#error m3_ao_region_size((DDR_POLICY_BASE + DDR_POLICY_SIZE - M3_SRAM_BASE)) used beyond (M3_SRAM_AO_SIZE)
#endif
#define SYS_CODE_SEC_BASE (DDR_POLICY_BASE + DDR_POLICY_SIZE)
#define SYS_CODE_SEC_RESERVED_SIZE (0x0)
#define SYS_CODE_SEC_SIZE (0x10980- SYS_CODE_SEC_RESERVED_SIZE)
#define EXPOSE_STORAGE_BASE (SYS_CODE_SEC_BASE + SYS_CODE_SEC_SIZE + SYS_CODE_SEC_RESERVED_SIZE)
#define EXPOSE_STORAGE_SIZE (0x400)
    #define EXC_SPECIAL_SAVE_BASE (EXPOSE_STORAGE_BASE)
    #define EXC_SPECIAL_SAVE_SIZE (0x30)
    #define DDRC_SAVE_TMP_BASE (EXC_SPECIAL_SAVE_BASE + EXC_SPECIAL_SAVE_SIZE)
 #define DDRC_SAVE_TMP_SIZE (0x10)
    #define OVERLAPPING_AREA_BASE (DDRC_SAVE_TMP_BASE + DDRC_SAVE_TMP_SIZE)
    #define OVERLAPPING_AREA_SIZE (0x3C0)
        #define DDRC_SAVE_BASE (OVERLAPPING_AREA_BASE)
        #define DDRC_SAVE_SIZE (0x3C0)
        #define INT_TRACK_BASE (OVERLAPPING_AREA_BASE)
        #define INT_TRACK_SIZE (0x2C0)
        #define TASK_TRACK_BASE (INT_TRACK_BASE + INT_TRACK_SIZE)
        #define TASK_TRACK_SIZE (0x100)
        #define REG_BACKUP_SRAM_BASE (OVERLAPPING_AREA_BASE)
        #define REG_BACKUP_SRAM_SIZE (0x70)
        #define STACK_BACKUP_SRAM_BASE (REG_BACKUP_SRAM_BASE + REG_BACKUP_SRAM_SIZE)
        #define STACK_BACKUP_SRAM_SIZE (0x300)
        #define PRIVATE_DATA_SRAM_BASE (STACK_BACKUP_SRAM_BASE + STACK_BACKUP_SRAM_SIZE)
        #define PRIVATE_DATA_SRAM_SIZE (0x50)
#define LITTLE_CLUSTER_PROFILE_BASE (EXPOSE_STORAGE_BASE + EXPOSE_STORAGE_SIZE)
#define LITTLE_CLUSTER_PROFILE_SIZE (0x200)
#define BIG_CLUSTER_PROFILE_BASE (LITTLE_CLUSTER_PROFILE_BASE + LITTLE_CLUSTER_PROFILE_SIZE)
#define BIG_CLUSTER_PROFILE_SIZE (0x200)
    #define CPU_BASE_PROFILE_BASE(n) (LITTLE_CLUSTER_PROFILE_BASE + (n) * LITTLE_CLUSTER_PROFILE_SIZE)
#define GPU_BASE_PROFILE_BASE (BIG_CLUSTER_PROFILE_BASE + BIG_CLUSTER_PROFILE_SIZE)
#define GPU_BASE_PROFILE_SIZE (0x200)
#define MODEM_PARA_BASE (GPU_BASE_PROFILE_BASE + GPU_BASE_PROFILE_SIZE)
#define MODEM_PARA_SIZE (0x40)
#define REG_BACKUP_BASE (MODEM_PARA_BASE + MODEM_PARA_SIZE)
#define REG_BACKUP_SIZE (0x1A0)
#define REG_PMU_BASE (REG_BACKUP_BASE + REG_BACKUP_SIZE)
#define REG_PMU_SIZE (0x20)
#define SYS_DATA_SEC_BASE (REG_PMU_BASE+REG_PMU_SIZE)
#define SYS_DATA_SEC_RESERVED_SIZE (0x100)
#define SYS_DATA_SEC_SIZE (0x3E00- SYS_DATA_SEC_RESERVED_SIZE)
#define SYS_HEAP_SEC_BASE (SYS_DATA_SEC_BASE+SYS_DATA_SEC_SIZE + SYS_DATA_SEC_RESERVED_SIZE)
#define SYS_HEAP_SEC_SIZE (0x200)
#define SYS_STACK_SEC_BASE (SYS_HEAP_SEC_BASE+SYS_HEAP_SEC_SIZE)
#define SYS_STACK_SEC_SIZE (0x400)
#define M3_SRAM_ADDR_OFFSET(addr) ((addr) - M3_SRAM_BASE)
#if defined(__CMSIS_RTOS)
#define LPRAM_ADDR_TO_AP_ADDR(addr) ((addr - SOC_LPMCU_LP_RAM_BASE_ADDR) + SOC_ACPU_LP_RAM_BASE_ADDR)
#endif
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif