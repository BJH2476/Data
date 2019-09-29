################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
source/%.obj: ../source/%.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccs910/ccs/tools/compiler/ti-cgt-arm_18.12.2.LTS/bin/armcl" -mv7M3 --code_state=16 --float_support=vfplib -me --include_path="C:/Users/jinhyuk/workspace_v9/CC1310_Clearn_Robot(ver_1.0)" --include_path="C:/Users/jinhyuk/workspace_v9/CC1310_Clearn_Robot(ver_1.0)/include" --include_path="C:/Users/jinhyuk/workspace_v9/CC1310_Clearn_Robot(ver_1.0)/source" --include_path="C:/ti/simplelink_cc13x0_sdk_3_20_00_23/source" --include_path="C:/ti/simplelink_cc13x0_sdk_3_20_00_23/kernel/nortos" --include_path="C:/ti/simplelink_cc13x0_sdk_3_20_00_23/kernel/nortos/posix" --include_path="C:/ti/ccs910/ccs/tools/compiler/ti-cgt-arm_18.12.2.LTS/include" --define=DeviceFamily_CC13X0 --define=CCFG_FORCE_VDDR_HH=0 --define=SUPPORT_PHY_CUSTOM --define=SUPPORT_PHY_50KBPS2GFSK --define=SUPPORT_PHY_625BPSLRM --define=SUPPORT_PHY_5KBPSSLLR -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="source/$(basename $(<F)).d_raw" --obj_directory="source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


