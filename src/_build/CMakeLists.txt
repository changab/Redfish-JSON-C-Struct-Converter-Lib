cmake_minimum_required(VERSION 2.6)

set(REDFISH_JSON_CS_LIB_SRC_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/..)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

include_directories (${REDFISH_JSON_CS_LIB_SRC_ROOT}/../include/)
include_directories (${REDFISH_JSON_CS_LIB_SRC_ROOT}/)
include_directories ("C:/Program Files (x86)/Windows Kits/8.0/Include/km/crt")
include_directories ("D:/DMTFGit/jansson-2.11/build/include")
file(GLOB REDFISH_JSON_CS_LIB_SRC ${REDFISH_JSON_CS_LIB_SRC_ROOT}/*.c)

file(GLOB REDFISH_JSON_CS_ACCOUNTSERVICE_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/AccountService/AccountService.V1_0_0/AccountService.V1_0_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/AccountService/AccountService.V1_0_2/AccountService.V1_0_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/AccountService/AccountService.V1_0_3/AccountService.V1_0_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/AccountService/AccountService.V1_0_4/AccountService.V1_0_4.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/AccountService/AccountService.V1_0_5/AccountService.V1_0_5.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/AccountService/AccountService.V1_0_6/AccountService.V1_0_6.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/AccountService/AccountService.V1_1_0/AccountService.V1_1_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/AccountService/AccountService.V1_1_1/AccountService.V1_1_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/AccountService/AccountService.V1_1_2/AccountService.V1_1_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/AccountService/AccountService.V1_1_3/AccountService.V1_1_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/AccountService/AccountService.V1_2_0/AccountService.V1_2_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/AccountService/AccountService.V1_2_1/AccountService.V1_2_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/AccountService/AccountService.V1_2_2/AccountService.V1_2_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/AccountService/AccountService.V1_2_3/AccountService.V1_2_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/AccountService/AccountService.V1_3_0/AccountService.V1_3_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/AccountService/AccountService.V1_3_1/AccountService.V1_3_1.c
)

file(GLOB REDFISH_JSON_CS_ACTIONINFO_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ActionInfo/ActionInfo.V1_0_0/ActionInfo.V1_0_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ActionInfo/ActionInfo.V1_0_1/ActionInfo.V1_0_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ActionInfo/ActionInfo.V1_0_2/ActionInfo.V1_0_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ActionInfo/ActionInfo.V1_0_3/ActionInfo.V1_0_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ActionInfo/ActionInfo.V1_0_4/ActionInfo.V1_0_4.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ActionInfo/ActionInfo.V1_1_0/ActionInfo.V1_1_0.c
)

file(GLOB REDFISH_JSON_CS_ASSEMBLY_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Assembly/Assembly.V1_0_0/Assembly.V1_0_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Assembly/Assembly.V1_0_1/Assembly.V1_0_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Assembly/Assembly.V1_1_0/Assembly.V1_1_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Assembly/Assembly.V1_1_1/Assembly.V1_1_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Assembly/Assembly.V1_2_0/Assembly.V1_2_0.c
)

file(GLOB REDFISH_JSON_CS_ATTRIBUTEREGISTRY_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/AttributeRegistry/AttributeRegistry.V1_0_0/AttributeRegistry.V1_0_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/AttributeRegistry/AttributeRegistry.V1_0_1/AttributeRegistry.V1_0_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/AttributeRegistry/AttributeRegistry.V1_0_2/AttributeRegistry.V1_0_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/AttributeRegistry/AttributeRegistry.V1_0_3/AttributeRegistry.V1_0_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/AttributeRegistry/AttributeRegistry.V1_0_4/AttributeRegistry.V1_0_4.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/AttributeRegistry/AttributeRegistry.V1_0_5/AttributeRegistry.V1_0_5.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/AttributeRegistry/AttributeRegistry.V1_1_0/AttributeRegistry.V1_1_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/AttributeRegistry/AttributeRegistry.V1_1_1/AttributeRegistry.V1_1_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/AttributeRegistry/AttributeRegistry.V1_1_2/AttributeRegistry.V1_1_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/AttributeRegistry/AttributeRegistry.V1_1_3/AttributeRegistry.V1_1_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/AttributeRegistry/AttributeRegistry.V1_1_4/AttributeRegistry.V1_1_4.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/AttributeRegistry/AttributeRegistry.V1_2_0/AttributeRegistry.V1_2_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/AttributeRegistry/AttributeRegistry.V1_2_1/AttributeRegistry.V1_2_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/AttributeRegistry/AttributeRegistry.V1_2_2/AttributeRegistry.V1_2_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/AttributeRegistry/AttributeRegistry.V1_3_0/AttributeRegistry.V1_3_0.c
)

file(GLOB REDFISH_JSON_CS_BIOS_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Bios/Bios.V1_0_0/Bios.V1_0_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Bios/Bios.V1_0_1/Bios.V1_0_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Bios/Bios.V1_0_2/Bios.V1_0_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Bios/Bios.V1_0_3/Bios.V1_0_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Bios/Bios.V1_0_4/Bios.V1_0_4.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Bios/Bios.V1_0_5/Bios.V1_0_5.c
)

file(GLOB REDFISH_JSON_CS_BOOTOPTION_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/BootOption/BootOption.V1_0_0/BootOption.V1_0_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/BootOption/BootOption.V1_0_1/BootOption.V1_0_1.c
)

file(GLOB REDFISH_JSON_CS_BOOTOPTIONCOLLECTION_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/BootOptionCollection/BootOptionCollection/BootOptionCollection.c
)

file(GLOB REDFISH_JSON_CS_CHASSIS_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Chassis/Chassis.V1_0_0/Chassis.V1_0_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Chassis/Chassis.V1_0_1/Chassis.V1_0_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Chassis/Chassis.V1_0_2/Chassis.V1_0_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Chassis/Chassis.V1_0_3/Chassis.V1_0_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Chassis/Chassis.V1_0_4/Chassis.V1_0_4.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Chassis/Chassis.V1_0_5/Chassis.V1_0_5.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Chassis/Chassis.V1_0_6/Chassis.V1_0_6.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Chassis/Chassis.V1_0_7/Chassis.V1_0_7.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Chassis/Chassis.V1_0_8/Chassis.V1_0_8.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Chassis/Chassis.V1_1_0/Chassis.V1_1_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Chassis/Chassis.V1_1_2/Chassis.V1_1_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Chassis/Chassis.V1_1_3/Chassis.V1_1_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Chassis/Chassis.V1_1_4/Chassis.V1_1_4.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Chassis/Chassis.V1_1_5/Chassis.V1_1_5.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Chassis/Chassis.V1_1_6/Chassis.V1_1_6.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Chassis/Chassis.V1_1_7/Chassis.V1_1_7.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Chassis/Chassis.V1_1_8/Chassis.V1_1_8.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Chassis/Chassis.V1_2_0/Chassis.V1_2_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Chassis/Chassis.V1_2_1/Chassis.V1_2_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Chassis/Chassis.V1_2_2/Chassis.V1_2_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Chassis/Chassis.V1_2_3/Chassis.V1_2_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Chassis/Chassis.V1_2_4/Chassis.V1_2_4.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Chassis/Chassis.V1_2_5/Chassis.V1_2_5.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Chassis/Chassis.V1_2_6/Chassis.V1_2_6.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Chassis/Chassis.V1_3_0/Chassis.V1_3_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Chassis/Chassis.V1_3_1/Chassis.V1_3_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Chassis/Chassis.V1_3_2/Chassis.V1_3_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Chassis/Chassis.V1_3_3/Chassis.V1_3_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Chassis/Chassis.V1_3_4/Chassis.V1_3_4.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Chassis/Chassis.V1_3_5/Chassis.V1_3_5.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Chassis/Chassis.V1_3_6/Chassis.V1_3_6.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Chassis/Chassis.V1_4_0/Chassis.V1_4_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Chassis/Chassis.V1_4_1/Chassis.V1_4_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Chassis/Chassis.V1_4_2/Chassis.V1_4_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Chassis/Chassis.V1_4_3/Chassis.V1_4_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Chassis/Chassis.V1_4_4/Chassis.V1_4_4.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Chassis/Chassis.V1_4_5/Chassis.V1_4_5.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Chassis/Chassis.V1_5_0/Chassis.V1_5_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Chassis/Chassis.V1_5_1/Chassis.V1_5_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Chassis/Chassis.V1_5_2/Chassis.V1_5_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Chassis/Chassis.V1_5_3/Chassis.V1_5_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Chassis/Chassis.V1_5_4/Chassis.V1_5_4.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Chassis/Chassis.V1_6_0/Chassis.V1_6_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Chassis/Chassis.V1_6_1/Chassis.V1_6_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Chassis/Chassis.V1_6_2/Chassis.V1_6_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Chassis/Chassis.V1_7_0/Chassis.V1_7_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Chassis/Chassis.V1_7_1/Chassis.V1_7_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Chassis/Chassis.V1_7_2/Chassis.V1_7_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Chassis/Chassis.V1_8_0/Chassis.V1_8_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Chassis/Chassis.V1_8_1/Chassis.V1_8_1.c
)

file(GLOB REDFISH_JSON_CS_CHASSISCOLLECTION_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ChassisCollection/ChassisCollection/ChassisCollection.c
)

file(GLOB REDFISH_JSON_CS_COMPOSITIONSERVICE_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/CompositionService/CompositionService.V1_0_0/CompositionService.V1_0_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/CompositionService/CompositionService.V1_0_1/CompositionService.V1_0_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/CompositionService/CompositionService.V1_0_2/CompositionService.V1_0_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/CompositionService/CompositionService.V1_1_0/CompositionService.V1_1_0.c
)

file(GLOB REDFISH_JSON_CS_COMPUTERSYSTEM_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ComputerSystem/ComputerSystem.V1_0_0/ComputerSystem.V1_0_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ComputerSystem/ComputerSystem.V1_0_1/ComputerSystem.V1_0_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ComputerSystem/ComputerSystem.V1_0_2/ComputerSystem.V1_0_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ComputerSystem/ComputerSystem.V1_0_3/ComputerSystem.V1_0_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ComputerSystem/ComputerSystem.V1_0_4/ComputerSystem.V1_0_4.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ComputerSystem/ComputerSystem.V1_0_5/ComputerSystem.V1_0_5.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ComputerSystem/ComputerSystem.V1_0_6/ComputerSystem.V1_0_6.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ComputerSystem/ComputerSystem.V1_0_7/ComputerSystem.V1_0_7.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ComputerSystem/ComputerSystem.V1_0_8/ComputerSystem.V1_0_8.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ComputerSystem/ComputerSystem.V1_0_9/ComputerSystem.V1_0_9.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ComputerSystem/ComputerSystem.V1_1_0/ComputerSystem.V1_1_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ComputerSystem/ComputerSystem.V1_1_1/ComputerSystem.V1_1_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ComputerSystem/ComputerSystem.V1_1_2/ComputerSystem.V1_1_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ComputerSystem/ComputerSystem.V1_1_3/ComputerSystem.V1_1_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ComputerSystem/ComputerSystem.V1_1_4/ComputerSystem.V1_1_4.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ComputerSystem/ComputerSystem.V1_1_5/ComputerSystem.V1_1_5.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ComputerSystem/ComputerSystem.V1_1_6/ComputerSystem.V1_1_6.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ComputerSystem/ComputerSystem.V1_1_7/ComputerSystem.V1_1_7.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ComputerSystem/ComputerSystem.V1_2_0/ComputerSystem.V1_2_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ComputerSystem/ComputerSystem.V1_2_1/ComputerSystem.V1_2_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ComputerSystem/ComputerSystem.V1_2_2/ComputerSystem.V1_2_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ComputerSystem/ComputerSystem.V1_2_3/ComputerSystem.V1_2_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ComputerSystem/ComputerSystem.V1_2_4/ComputerSystem.V1_2_4.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ComputerSystem/ComputerSystem.V1_2_5/ComputerSystem.V1_2_5.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ComputerSystem/ComputerSystem.V1_2_6/ComputerSystem.V1_2_6.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ComputerSystem/ComputerSystem.V1_3_0/ComputerSystem.V1_3_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ComputerSystem/ComputerSystem.V1_3_1/ComputerSystem.V1_3_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ComputerSystem/ComputerSystem.V1_3_2/ComputerSystem.V1_3_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ComputerSystem/ComputerSystem.V1_3_3/ComputerSystem.V1_3_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ComputerSystem/ComputerSystem.V1_3_4/ComputerSystem.V1_3_4.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ComputerSystem/ComputerSystem.V1_3_5/ComputerSystem.V1_3_5.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ComputerSystem/ComputerSystem.V1_4_0/ComputerSystem.V1_4_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ComputerSystem/ComputerSystem.V1_4_1/ComputerSystem.V1_4_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ComputerSystem/ComputerSystem.V1_4_2/ComputerSystem.V1_4_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ComputerSystem/ComputerSystem.V1_4_3/ComputerSystem.V1_4_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ComputerSystem/ComputerSystem.V1_4_4/ComputerSystem.V1_4_4.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ComputerSystem/ComputerSystem.V1_5_0/ComputerSystem.V1_5_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ComputerSystem/ComputerSystem.V1_5_1/ComputerSystem.V1_5_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ComputerSystem/ComputerSystem.V1_5_2/ComputerSystem.V1_5_2.c
)

file(GLOB REDFISH_JSON_CS_COMPUTERSYSTEMCOLLECTION_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ComputerSystemCollection/ComputerSystemCollection/ComputerSystemCollection.c
)

file(GLOB REDFISH_JSON_CS_DRIVE_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Drive/Drive.V1_0_0/Drive.V1_0_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Drive/Drive.V1_0_1/Drive.V1_0_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Drive/Drive.V1_0_2/Drive.V1_0_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Drive/Drive.V1_0_3/Drive.V1_0_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Drive/Drive.V1_0_4/Drive.V1_0_4.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Drive/Drive.V1_0_5/Drive.V1_0_5.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Drive/Drive.V1_0_6/Drive.V1_0_6.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Drive/Drive.V1_1_0/Drive.V1_1_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Drive/Drive.V1_1_1/Drive.V1_1_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Drive/Drive.V1_1_2/Drive.V1_1_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Drive/Drive.V1_1_3/Drive.V1_1_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Drive/Drive.V1_1_4/Drive.V1_1_4.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Drive/Drive.V1_1_5/Drive.V1_1_5.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Drive/Drive.V1_2_0/Drive.V1_2_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Drive/Drive.V1_2_1/Drive.V1_2_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Drive/Drive.V1_2_2/Drive.V1_2_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Drive/Drive.V1_2_3/Drive.V1_2_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Drive/Drive.V1_3_0/Drive.V1_3_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Drive/Drive.V1_3_1/Drive.V1_3_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Drive/Drive.V1_3_2/Drive.V1_3_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Drive/Drive.V1_4_0/Drive.V1_4_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Drive/Drive.V1_4_1/Drive.V1_4_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Drive/Drive.V1_4_2/Drive.V1_4_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Drive/Drive.V1_5_0/Drive.V1_5_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Drive/Drive.V1_5_1/Drive.V1_5_1.c
)

file(GLOB REDFISH_JSON_CS_ENDPOINT_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Endpoint/Endpoint.V1_0_0/Endpoint.V1_0_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Endpoint/Endpoint.V1_0_1/Endpoint.V1_0_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Endpoint/Endpoint.V1_0_2/Endpoint.V1_0_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Endpoint/Endpoint.V1_0_3/Endpoint.V1_0_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Endpoint/Endpoint.V1_0_4/Endpoint.V1_0_4.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Endpoint/Endpoint.V1_0_5/Endpoint.V1_0_5.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Endpoint/Endpoint.V1_1_0/Endpoint.V1_1_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Endpoint/Endpoint.V1_1_1/Endpoint.V1_1_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Endpoint/Endpoint.V1_1_2/Endpoint.V1_1_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Endpoint/Endpoint.V1_2_0/Endpoint.V1_2_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Endpoint/Endpoint.V1_2_1/Endpoint.V1_2_1.c
)

file(GLOB REDFISH_JSON_CS_ENDPOINTCOLLECTION_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/EndpointCollection/EndpointCollection/EndpointCollection.c
)

file(GLOB REDFISH_JSON_CS_ETHERNETINTERFACE_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/EthernetInterface/EthernetInterface.V1_0_0/EthernetInterface.V1_0_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/EthernetInterface/EthernetInterface.V1_0_2/EthernetInterface.V1_0_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/EthernetInterface/EthernetInterface.V1_0_3/EthernetInterface.V1_0_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/EthernetInterface/EthernetInterface.V1_0_4/EthernetInterface.V1_0_4.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/EthernetInterface/EthernetInterface.V1_0_5/EthernetInterface.V1_0_5.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/EthernetInterface/EthernetInterface.V1_0_6/EthernetInterface.V1_0_6.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/EthernetInterface/EthernetInterface.V1_1_0/EthernetInterface.V1_1_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/EthernetInterface/EthernetInterface.V1_1_1/EthernetInterface.V1_1_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/EthernetInterface/EthernetInterface.V1_1_2/EthernetInterface.V1_1_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/EthernetInterface/EthernetInterface.V1_1_3/EthernetInterface.V1_1_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/EthernetInterface/EthernetInterface.V1_1_4/EthernetInterface.V1_1_4.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/EthernetInterface/EthernetInterface.V1_2_0/EthernetInterface.V1_2_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/EthernetInterface/EthernetInterface.V1_2_1/EthernetInterface.V1_2_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/EthernetInterface/EthernetInterface.V1_2_2/EthernetInterface.V1_2_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/EthernetInterface/EthernetInterface.V1_2_3/EthernetInterface.V1_2_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/EthernetInterface/EthernetInterface.V1_3_0/EthernetInterface.V1_3_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/EthernetInterface/EthernetInterface.V1_3_1/EthernetInterface.V1_3_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/EthernetInterface/EthernetInterface.V1_3_2/EthernetInterface.V1_3_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/EthernetInterface/EthernetInterface.V1_4_0/EthernetInterface.V1_4_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/EthernetInterface/EthernetInterface.V1_4_1/EthernetInterface.V1_4_1.c
)

file(GLOB REDFISH_JSON_CS_ETHERNETINTERFACECOLLECTION_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/EthernetInterfaceCollection/EthernetInterfaceCollection/EthernetInterfaceCollection.c
)

file(GLOB REDFISH_JSON_CS_EVENT_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Event/Event.V1_0_0/Event.V1_0_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Event/Event.V1_0_2/Event.V1_0_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Event/Event.V1_0_3/Event.V1_0_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Event/Event.V1_0_4/Event.V1_0_4.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Event/Event.V1_0_5/Event.V1_0_5.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Event/Event.V1_0_6/Event.V1_0_6.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Event/Event.V1_0_7/Event.V1_0_7.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Event/Event.V1_0_8/Event.V1_0_8.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Event/Event.V1_1_0/Event.V1_1_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Event/Event.V1_1_1/Event.V1_1_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Event/Event.V1_1_2/Event.V1_1_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Event/Event.V1_1_3/Event.V1_1_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Event/Event.V1_1_4/Event.V1_1_4.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Event/Event.V1_1_5/Event.V1_1_5.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Event/Event.V1_1_6/Event.V1_1_6.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Event/Event.V1_2_0/Event.V1_2_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Event/Event.V1_2_1/Event.V1_2_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Event/Event.V1_2_2/Event.V1_2_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Event/Event.V1_2_3/Event.V1_2_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Event/Event.V1_3_0/Event.V1_3_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Event/Event.V1_3_1/Event.V1_3_1.c
)

file(GLOB REDFISH_JSON_CS_EVENTDESTINATION_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/EventDestination/EventDestination.V1_0_0/EventDestination.V1_0_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/EventDestination/EventDestination.V1_0_2/EventDestination.V1_0_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/EventDestination/EventDestination.V1_0_3/EventDestination.V1_0_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/EventDestination/EventDestination.V1_0_4/EventDestination.V1_0_4.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/EventDestination/EventDestination.V1_0_5/EventDestination.V1_0_5.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/EventDestination/EventDestination.V1_0_6/EventDestination.V1_0_6.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/EventDestination/EventDestination.V1_1_0/EventDestination.V1_1_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/EventDestination/EventDestination.V1_1_1/EventDestination.V1_1_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/EventDestination/EventDestination.V1_1_2/EventDestination.V1_1_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/EventDestination/EventDestination.V1_1_3/EventDestination.V1_1_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/EventDestination/EventDestination.V1_1_4/EventDestination.V1_1_4.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/EventDestination/EventDestination.V1_1_5/EventDestination.V1_1_5.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/EventDestination/EventDestination.V1_2_0/EventDestination.V1_2_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/EventDestination/EventDestination.V1_2_1/EventDestination.V1_2_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/EventDestination/EventDestination.V1_2_2/EventDestination.V1_2_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/EventDestination/EventDestination.V1_2_3/EventDestination.V1_2_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/EventDestination/EventDestination.V1_3_0/EventDestination.V1_3_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/EventDestination/EventDestination.V1_3_1/EventDestination.V1_3_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/EventDestination/EventDestination.V1_4_0/EventDestination.V1_4_0.c
)

file(GLOB REDFISH_JSON_CS_EVENTDESTINATIONCOLLECTION_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/EventDestinationCollection/EventDestinationCollection/EventDestinationCollection.c
)

file(GLOB REDFISH_JSON_CS_EVENTSERVICE_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/EventService/EventService.V1_0_0/EventService.V1_0_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/EventService/EventService.V1_0_2/EventService.V1_0_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/EventService/EventService.V1_0_3/EventService.V1_0_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/EventService/EventService.V1_0_4/EventService.V1_0_4.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/EventService/EventService.V1_0_5/EventService.V1_0_5.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/EventService/EventService.V1_0_6/EventService.V1_0_6.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/EventService/EventService.V1_0_7/EventService.V1_0_7.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/EventService/EventService.V1_0_8/EventService.V1_0_8.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/EventService/EventService.V1_1_0/EventService.V1_1_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/EventService/EventService.V1_1_1/EventService.V1_1_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/EventService/EventService.V1_2_0/EventService.V1_2_0.c
)

file(GLOB REDFISH_JSON_CS_EXTERNALACCOUNTPROVIDER_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ExternalAccountProvider/ExternalAccountProvider.V1_0_0/ExternalAccountProvider.V1_0_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ExternalAccountProvider/ExternalAccountProvider.V1_0_1/ExternalAccountProvider.V1_0_1.c
)

file(GLOB REDFISH_JSON_CS_EXTERNALACCOUNTPROVIDERCOLLECTION_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ExternalAccountProviderCollection/ExternalAccountProviderCollection/ExternalAccountProviderCollection.c
)

file(GLOB REDFISH_JSON_CS_FABRIC_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Fabric/Fabric.V1_0_0/Fabric.V1_0_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Fabric/Fabric.V1_0_1/Fabric.V1_0_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Fabric/Fabric.V1_0_2/Fabric.V1_0_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Fabric/Fabric.V1_0_3/Fabric.V1_0_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Fabric/Fabric.V1_0_4/Fabric.V1_0_4.c
)

file(GLOB REDFISH_JSON_CS_FABRICCOLLECTION_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/FabricCollection/FabricCollection/FabricCollection.c
)

file(GLOB REDFISH_JSON_CS_HOSTINTERFACE_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/HostInterface/HostInterface.V1_0_0/HostInterface.V1_0_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/HostInterface/HostInterface.V1_0_1/HostInterface.V1_0_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/HostInterface/HostInterface.V1_0_2/HostInterface.V1_0_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/HostInterface/HostInterface.V1_0_3/HostInterface.V1_0_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/HostInterface/HostInterface.V1_1_0/HostInterface.V1_1_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/HostInterface/HostInterface.V1_1_1/HostInterface.V1_1_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/HostInterface/HostInterface.V1_1_2/HostInterface.V1_1_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/HostInterface/HostInterface.V1_1_3/HostInterface.V1_1_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/HostInterface/HostInterface.V1_2_0/HostInterface.V1_2_0.c
)

file(GLOB REDFISH_JSON_CS_HOSTINTERFACECOLLECTION_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/HostInterfaceCollection/HostInterfaceCollection/HostInterfaceCollection.c
)

file(GLOB REDFISH_JSON_CS_JOB_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Job/Job.V1_0_0/Job.V1_0_0.c
)

file(GLOB REDFISH_JSON_CS_JOBCOLLECTION_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/JobCollection/JobCollection/JobCollection.c
)

file(GLOB REDFISH_JSON_CS_JOBSERVICE_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/JobService/JobService.V1_0_0/JobService.V1_0_0.c
)

file(GLOB REDFISH_JSON_CS_JSONSCHEMAFILE_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/JsonSchemaFile/JsonSchemaFile.V1_0_0/JsonSchemaFile.V1_0_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/JsonSchemaFile/JsonSchemaFile.V1_0_2/JsonSchemaFile.V1_0_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/JsonSchemaFile/JsonSchemaFile.V1_0_3/JsonSchemaFile.V1_0_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/JsonSchemaFile/JsonSchemaFile.V1_0_4/JsonSchemaFile.V1_0_4.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/JsonSchemaFile/JsonSchemaFile.V1_0_5/JsonSchemaFile.V1_0_5.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/JsonSchemaFile/JsonSchemaFile.V1_1_0/JsonSchemaFile.V1_1_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/JsonSchemaFile/JsonSchemaFile.V1_1_1/JsonSchemaFile.V1_1_1.c
)

file(GLOB REDFISH_JSON_CS_JSONSCHEMAFILECOLLECTION_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/JsonSchemaFileCollection/JsonSchemaFileCollection/JsonSchemaFileCollection.c
)

file(GLOB REDFISH_JSON_CS_LOGENTRY_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/LogEntry/LogEntry.V1_0_0/LogEntry.V1_0_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/LogEntry/LogEntry.V1_0_2/LogEntry.V1_0_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/LogEntry/LogEntry.V1_0_3/LogEntry.V1_0_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/LogEntry/LogEntry.V1_0_4/LogEntry.V1_0_4.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/LogEntry/LogEntry.V1_0_5/LogEntry.V1_0_5.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/LogEntry/LogEntry.V1_0_6/LogEntry.V1_0_6.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/LogEntry/LogEntry.V1_0_7/LogEntry.V1_0_7.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/LogEntry/LogEntry.V1_1_0/LogEntry.V1_1_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/LogEntry/LogEntry.V1_1_1/LogEntry.V1_1_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/LogEntry/LogEntry.V1_1_2/LogEntry.V1_1_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/LogEntry/LogEntry.V1_1_3/LogEntry.V1_1_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/LogEntry/LogEntry.V1_1_4/LogEntry.V1_1_4.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/LogEntry/LogEntry.V1_1_5/LogEntry.V1_1_5.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/LogEntry/LogEntry.V1_2_0/LogEntry.V1_2_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/LogEntry/LogEntry.V1_2_1/LogEntry.V1_2_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/LogEntry/LogEntry.V1_2_2/LogEntry.V1_2_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/LogEntry/LogEntry.V1_2_3/LogEntry.V1_2_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/LogEntry/LogEntry.V1_3_0/LogEntry.V1_3_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/LogEntry/LogEntry.V1_3_1/LogEntry.V1_3_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/LogEntry/LogEntry.V1_3_2/LogEntry.V1_3_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/LogEntry/LogEntry.V1_4_0/LogEntry.V1_4_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/LogEntry/LogEntry.V1_4_1/LogEntry.V1_4_1.c
)

file(GLOB REDFISH_JSON_CS_LOGENTRYCOLLECTION_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/LogEntryCollection/LogEntryCollection/LogEntryCollection.c
)

file(GLOB REDFISH_JSON_CS_LOGSERVICE_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/LogService/LogService.V1_0_0/LogService.V1_0_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/LogService/LogService.V1_0_2/LogService.V1_0_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/LogService/LogService.V1_0_3/LogService.V1_0_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/LogService/LogService.V1_0_4/LogService.V1_0_4.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/LogService/LogService.V1_0_5/LogService.V1_0_5.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/LogService/LogService.V1_0_6/LogService.V1_0_6.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/LogService/LogService.V1_1_0/LogService.V1_1_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/LogService/LogService.V1_1_1/LogService.V1_1_1.c
)

file(GLOB REDFISH_JSON_CS_LOGSERVICECOLLECTION_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/LogServiceCollection/LogServiceCollection/LogServiceCollection.c
)

file(GLOB REDFISH_JSON_CS_MANAGER_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Manager/Manager.V1_0_0/Manager.V1_0_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Manager/Manager.V1_0_1/Manager.V1_0_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Manager/Manager.V1_0_2/Manager.V1_0_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Manager/Manager.V1_0_3/Manager.V1_0_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Manager/Manager.V1_0_4/Manager.V1_0_4.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Manager/Manager.V1_0_5/Manager.V1_0_5.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Manager/Manager.V1_0_6/Manager.V1_0_6.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Manager/Manager.V1_0_7/Manager.V1_0_7.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Manager/Manager.V1_0_8/Manager.V1_0_8.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Manager/Manager.V1_1_0/Manager.V1_1_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Manager/Manager.V1_1_1/Manager.V1_1_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Manager/Manager.V1_1_2/Manager.V1_1_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Manager/Manager.V1_1_3/Manager.V1_1_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Manager/Manager.V1_1_4/Manager.V1_1_4.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Manager/Manager.V1_1_5/Manager.V1_1_5.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Manager/Manager.V1_1_6/Manager.V1_1_6.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Manager/Manager.V1_2_0/Manager.V1_2_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Manager/Manager.V1_2_1/Manager.V1_2_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Manager/Manager.V1_2_2/Manager.V1_2_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Manager/Manager.V1_2_3/Manager.V1_2_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Manager/Manager.V1_2_4/Manager.V1_2_4.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Manager/Manager.V1_2_5/Manager.V1_2_5.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Manager/Manager.V1_2_6/Manager.V1_2_6.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Manager/Manager.V1_3_0/Manager.V1_3_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Manager/Manager.V1_3_1/Manager.V1_3_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Manager/Manager.V1_3_2/Manager.V1_3_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Manager/Manager.V1_3_3/Manager.V1_3_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Manager/Manager.V1_3_4/Manager.V1_3_4.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Manager/Manager.V1_3_5/Manager.V1_3_5.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Manager/Manager.V1_4_0/Manager.V1_4_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Manager/Manager.V1_4_1/Manager.V1_4_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Manager/Manager.V1_4_2/Manager.V1_4_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Manager/Manager.V1_5_0/Manager.V1_5_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Manager/Manager.V1_5_1/Manager.V1_5_1.c
)

file(GLOB REDFISH_JSON_CS_MANAGERACCOUNT_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ManagerAccount/ManagerAccount.V1_0_0/ManagerAccount.V1_0_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ManagerAccount/ManagerAccount.V1_0_2/ManagerAccount.V1_0_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ManagerAccount/ManagerAccount.V1_0_3/ManagerAccount.V1_0_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ManagerAccount/ManagerAccount.V1_0_4/ManagerAccount.V1_0_4.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ManagerAccount/ManagerAccount.V1_0_5/ManagerAccount.V1_0_5.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ManagerAccount/ManagerAccount.V1_0_6/ManagerAccount.V1_0_6.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ManagerAccount/ManagerAccount.V1_0_7/ManagerAccount.V1_0_7.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ManagerAccount/ManagerAccount.V1_1_0/ManagerAccount.V1_1_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ManagerAccount/ManagerAccount.V1_1_1/ManagerAccount.V1_1_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ManagerAccount/ManagerAccount.V1_1_2/ManagerAccount.V1_1_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ManagerAccount/ManagerAccount.V1_1_3/ManagerAccount.V1_1_3.c
)

file(GLOB REDFISH_JSON_CS_MANAGERACCOUNTCOLLECTION_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ManagerAccountCollection/ManagerAccountCollection/ManagerAccountCollection.c
)

file(GLOB REDFISH_JSON_CS_MANAGERCOLLECTION_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ManagerCollection/ManagerCollection/ManagerCollection.c
)

file(GLOB REDFISH_JSON_CS_MANAGERNETWORKPROTOCOL_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ManagerNetworkProtocol/ManagerNetworkProtocol.V1_0_0/ManagerNetworkProtocol.V1_0_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ManagerNetworkProtocol/ManagerNetworkProtocol.V1_0_2/ManagerNetworkProtocol.V1_0_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ManagerNetworkProtocol/ManagerNetworkProtocol.V1_0_3/ManagerNetworkProtocol.V1_0_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ManagerNetworkProtocol/ManagerNetworkProtocol.V1_0_4/ManagerNetworkProtocol.V1_0_4.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ManagerNetworkProtocol/ManagerNetworkProtocol.V1_0_5/ManagerNetworkProtocol.V1_0_5.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ManagerNetworkProtocol/ManagerNetworkProtocol.V1_1_0/ManagerNetworkProtocol.V1_1_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ManagerNetworkProtocol/ManagerNetworkProtocol.V1_1_1/ManagerNetworkProtocol.V1_1_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ManagerNetworkProtocol/ManagerNetworkProtocol.V1_1_2/ManagerNetworkProtocol.V1_1_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ManagerNetworkProtocol/ManagerNetworkProtocol.V1_2_0/ManagerNetworkProtocol.V1_2_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ManagerNetworkProtocol/ManagerNetworkProtocol.V1_2_1/ManagerNetworkProtocol.V1_2_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ManagerNetworkProtocol/ManagerNetworkProtocol.V1_3_0/ManagerNetworkProtocol.V1_3_0.c
)

file(GLOB REDFISH_JSON_CS_MEMORY_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Memory/Memory.V1_0_0/Memory.V1_0_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Memory/Memory.V1_0_1/Memory.V1_0_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Memory/Memory.V1_0_2/Memory.V1_0_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Memory/Memory.V1_0_3/Memory.V1_0_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Memory/Memory.V1_0_4/Memory.V1_0_4.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Memory/Memory.V1_0_5/Memory.V1_0_5.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Memory/Memory.V1_1_0/Memory.V1_1_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Memory/Memory.V1_1_1/Memory.V1_1_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Memory/Memory.V1_1_2/Memory.V1_1_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Memory/Memory.V1_1_3/Memory.V1_1_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Memory/Memory.V1_1_4/Memory.V1_1_4.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Memory/Memory.V1_2_0/Memory.V1_2_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Memory/Memory.V1_2_1/Memory.V1_2_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Memory/Memory.V1_2_2/Memory.V1_2_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Memory/Memory.V1_2_3/Memory.V1_2_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Memory/Memory.V1_3_0/Memory.V1_3_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Memory/Memory.V1_3_1/Memory.V1_3_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Memory/Memory.V1_3_2/Memory.V1_3_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Memory/Memory.V1_3_3/Memory.V1_3_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Memory/Memory.V1_4_0/Memory.V1_4_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Memory/Memory.V1_4_1/Memory.V1_4_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Memory/Memory.V1_4_2/Memory.V1_4_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Memory/Memory.V1_4_3/Memory.V1_4_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Memory/Memory.V1_5_0/Memory.V1_5_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Memory/Memory.V1_5_1/Memory.V1_5_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Memory/Memory.V1_5_2/Memory.V1_5_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Memory/Memory.V1_6_0/Memory.V1_6_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Memory/Memory.V1_6_1/Memory.V1_6_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Memory/Memory.V1_7_0/Memory.V1_7_0.c
)

file(GLOB REDFISH_JSON_CS_MEMORYCHUNKS_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/MemoryChunks/MemoryChunks.V1_0_0/MemoryChunks.V1_0_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/MemoryChunks/MemoryChunks.V1_0_1/MemoryChunks.V1_0_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/MemoryChunks/MemoryChunks.V1_0_2/MemoryChunks.V1_0_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/MemoryChunks/MemoryChunks.V1_0_3/MemoryChunks.V1_0_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/MemoryChunks/MemoryChunks.V1_1_0/MemoryChunks.V1_1_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/MemoryChunks/MemoryChunks.V1_1_1/MemoryChunks.V1_1_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/MemoryChunks/MemoryChunks.V1_2_0/MemoryChunks.V1_2_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/MemoryChunks/MemoryChunks.V1_2_1/MemoryChunks.V1_2_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/MemoryChunks/MemoryChunks.V1_2_2/MemoryChunks.V1_2_2.c
)

file(GLOB REDFISH_JSON_CS_MEMORYCHUNKSCOLLECTION_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/MemoryChunksCollection/MemoryChunksCollection/MemoryChunksCollection.c
)

file(GLOB REDFISH_JSON_CS_MEMORYCOLLECTION_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/MemoryCollection/MemoryCollection/MemoryCollection.c
)

file(GLOB REDFISH_JSON_CS_MEMORYDOMAIN_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/MemoryDomain/MemoryDomain.V1_0_0/MemoryDomain.V1_0_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/MemoryDomain/MemoryDomain.V1_0_1/MemoryDomain.V1_0_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/MemoryDomain/MemoryDomain.V1_0_2/MemoryDomain.V1_0_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/MemoryDomain/MemoryDomain.V1_0_3/MemoryDomain.V1_0_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/MemoryDomain/MemoryDomain.V1_1_0/MemoryDomain.V1_1_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/MemoryDomain/MemoryDomain.V1_1_1/MemoryDomain.V1_1_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/MemoryDomain/MemoryDomain.V1_1_2/MemoryDomain.V1_1_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/MemoryDomain/MemoryDomain.V1_2_0/MemoryDomain.V1_2_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/MemoryDomain/MemoryDomain.V1_2_1/MemoryDomain.V1_2_1.c
)

file(GLOB REDFISH_JSON_CS_MEMORYDOMAINCOLLECTION_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/MemoryDomainCollection/MemoryDomainCollection/MemoryDomainCollection.c
)

file(GLOB REDFISH_JSON_CS_MEMORYMETRICS_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/MemoryMetrics/MemoryMetrics.V1_0_0/MemoryMetrics.V1_0_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/MemoryMetrics/MemoryMetrics.V1_0_1/MemoryMetrics.V1_0_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/MemoryMetrics/MemoryMetrics.V1_0_2/MemoryMetrics.V1_0_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/MemoryMetrics/MemoryMetrics.V1_0_3/MemoryMetrics.V1_0_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/MemoryMetrics/MemoryMetrics.V1_0_4/MemoryMetrics.V1_0_4.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/MemoryMetrics/MemoryMetrics.V1_1_1/MemoryMetrics.V1_1_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/MemoryMetrics/MemoryMetrics.V1_1_2/MemoryMetrics.V1_1_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/MemoryMetrics/MemoryMetrics.V1_1_3/MemoryMetrics.V1_1_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/MemoryMetrics/MemoryMetrics.V1_1_4/MemoryMetrics.V1_1_4.c
)

file(GLOB REDFISH_JSON_CS_MESSAGEREGISTRY_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/MessageRegistry/MessageRegistry.V1_0_0/MessageRegistry.V1_0_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/MessageRegistry/MessageRegistry.V1_0_2/MessageRegistry.V1_0_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/MessageRegistry/MessageRegistry.V1_0_3/MessageRegistry.V1_0_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/MessageRegistry/MessageRegistry.V1_0_4/MessageRegistry.V1_0_4.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/MessageRegistry/MessageRegistry.V1_0_5/MessageRegistry.V1_0_5.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/MessageRegistry/MessageRegistry.V1_0_6/MessageRegistry.V1_0_6.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/MessageRegistry/MessageRegistry.V1_1_0/MessageRegistry.V1_1_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/MessageRegistry/MessageRegistry.V1_1_1/MessageRegistry.V1_1_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/MessageRegistry/MessageRegistry.V1_1_2/MessageRegistry.V1_1_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/MessageRegistry/MessageRegistry.V1_2_0/MessageRegistry.V1_2_0.c
)

file(GLOB REDFISH_JSON_CS_MESSAGEREGISTRYCOLLECTION_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/MessageRegistryCollection/MessageRegistryCollection/MessageRegistryCollection.c
)

file(GLOB REDFISH_JSON_CS_MESSAGEREGISTRYFILE_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/MessageRegistryFile/MessageRegistryFile.V1_0_0/MessageRegistryFile.V1_0_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/MessageRegistryFile/MessageRegistryFile.V1_0_2/MessageRegistryFile.V1_0_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/MessageRegistryFile/MessageRegistryFile.V1_0_3/MessageRegistryFile.V1_0_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/MessageRegistryFile/MessageRegistryFile.V1_0_4/MessageRegistryFile.V1_0_4.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/MessageRegistryFile/MessageRegistryFile.V1_0_5/MessageRegistryFile.V1_0_5.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/MessageRegistryFile/MessageRegistryFile.V1_1_0/MessageRegistryFile.V1_1_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/MessageRegistryFile/MessageRegistryFile.V1_1_1/MessageRegistryFile.V1_1_1.c
)

file(GLOB REDFISH_JSON_CS_MESSAGEREGISTRYFILECOLLECTION_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/MessageRegistryFileCollection/MessageRegistryFileCollection/MessageRegistryFileCollection.c
)

file(GLOB REDFISH_JSON_CS_METRICDEFINITION_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/MetricDefinition/MetricDefinition.V1_0_0/MetricDefinition.V1_0_0.c
)

file(GLOB REDFISH_JSON_CS_METRICDEFINITIONCOLLECTION_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/MetricDefinitionCollection/MetricDefinitionCollection/MetricDefinitionCollection.c
)

file(GLOB REDFISH_JSON_CS_METRICREPORT_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/MetricReport/MetricReport.V1_0_0/MetricReport.V1_0_0.c
)

file(GLOB REDFISH_JSON_CS_METRICREPORTCOLLECTION_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/MetricReportCollection/MetricReportCollection/MetricReportCollection.c
)

file(GLOB REDFISH_JSON_CS_METRICREPORTDEFINITION_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/MetricReportDefinition/MetricReportDefinition.V1_0_0/MetricReportDefinition.V1_0_0.c
)

file(GLOB REDFISH_JSON_CS_METRICREPORTDEFINITIONCOLLECTION_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/MetricReportDefinitionCollection/MetricReportDefinitionCollection/MetricReportDefinitionCollection.c
)

file(GLOB REDFISH_JSON_CS_NETWORKADAPTER_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/NetworkAdapter/NetworkAdapter.V1_0_0/NetworkAdapter.V1_0_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/NetworkAdapter/NetworkAdapter.V1_0_1/NetworkAdapter.V1_0_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/NetworkAdapter/NetworkAdapter.V1_0_2/NetworkAdapter.V1_0_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/NetworkAdapter/NetworkAdapter.V1_1_0/NetworkAdapter.V1_1_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/NetworkAdapter/NetworkAdapter.V1_1_1/NetworkAdapter.V1_1_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/NetworkAdapter/NetworkAdapter.V1_2_0/NetworkAdapter.V1_2_0.c
)

file(GLOB REDFISH_JSON_CS_NETWORKADAPTERCOLLECTION_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/NetworkAdapterCollection/NetworkAdapterCollection/NetworkAdapterCollection.c
)

file(GLOB REDFISH_JSON_CS_NETWORKDEVICEFUNCTION_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/NetworkDeviceFunction/NetworkDeviceFunction.V1_0_0/NetworkDeviceFunction.V1_0_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/NetworkDeviceFunction/NetworkDeviceFunction.V1_0_1/NetworkDeviceFunction.V1_0_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/NetworkDeviceFunction/NetworkDeviceFunction.V1_0_2/NetworkDeviceFunction.V1_0_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/NetworkDeviceFunction/NetworkDeviceFunction.V1_0_3/NetworkDeviceFunction.V1_0_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/NetworkDeviceFunction/NetworkDeviceFunction.V1_0_4/NetworkDeviceFunction.V1_0_4.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/NetworkDeviceFunction/NetworkDeviceFunction.V1_1_0/NetworkDeviceFunction.V1_1_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/NetworkDeviceFunction/NetworkDeviceFunction.V1_1_1/NetworkDeviceFunction.V1_1_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/NetworkDeviceFunction/NetworkDeviceFunction.V1_1_2/NetworkDeviceFunction.V1_1_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/NetworkDeviceFunction/NetworkDeviceFunction.V1_1_3/NetworkDeviceFunction.V1_1_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/NetworkDeviceFunction/NetworkDeviceFunction.V1_2_0/NetworkDeviceFunction.V1_2_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/NetworkDeviceFunction/NetworkDeviceFunction.V1_2_1/NetworkDeviceFunction.V1_2_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/NetworkDeviceFunction/NetworkDeviceFunction.V1_2_2/NetworkDeviceFunction.V1_2_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/NetworkDeviceFunction/NetworkDeviceFunction.V1_2_3/NetworkDeviceFunction.V1_2_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/NetworkDeviceFunction/NetworkDeviceFunction.V1_3_0/NetworkDeviceFunction.V1_3_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/NetworkDeviceFunction/NetworkDeviceFunction.V1_3_1/NetworkDeviceFunction.V1_3_1.c
)

file(GLOB REDFISH_JSON_CS_NETWORKDEVICEFUNCTIONCOLLECTION_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/NetworkDeviceFunctionCollection/NetworkDeviceFunctionCollection/NetworkDeviceFunctionCollection.c
)

file(GLOB REDFISH_JSON_CS_NETWORKINTERFACE_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/NetworkInterface/NetworkInterface.V1_0_0/NetworkInterface.V1_0_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/NetworkInterface/NetworkInterface.V1_0_1/NetworkInterface.V1_0_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/NetworkInterface/NetworkInterface.V1_0_2/NetworkInterface.V1_0_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/NetworkInterface/NetworkInterface.V1_1_0/NetworkInterface.V1_1_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/NetworkInterface/NetworkInterface.V1_1_1/NetworkInterface.V1_1_1.c
)

file(GLOB REDFISH_JSON_CS_NETWORKINTERFACECOLLECTION_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/NetworkInterfaceCollection/NetworkInterfaceCollection/NetworkInterfaceCollection.c
)

file(GLOB REDFISH_JSON_CS_NETWORKPORT_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/NetworkPort/NetworkPort.V1_0_0/NetworkPort.V1_0_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/NetworkPort/NetworkPort.V1_0_1/NetworkPort.V1_0_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/NetworkPort/NetworkPort.V1_0_2/NetworkPort.V1_0_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/NetworkPort/NetworkPort.V1_0_3/NetworkPort.V1_0_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/NetworkPort/NetworkPort.V1_1_0/NetworkPort.V1_1_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/NetworkPort/NetworkPort.V1_1_1/NetworkPort.V1_1_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/NetworkPort/NetworkPort.V1_1_2/NetworkPort.V1_1_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/NetworkPort/NetworkPort.V1_2_0/NetworkPort.V1_2_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/NetworkPort/NetworkPort.V1_2_1/NetworkPort.V1_2_1.c
)

file(GLOB REDFISH_JSON_CS_NETWORKPORTCOLLECTION_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/NetworkPortCollection/NetworkPortCollection/NetworkPortCollection.c
)

file(GLOB REDFISH_JSON_CS_PCIEDEVICE_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/PCIeDevice/PCIeDevice.V1_0_0/PCIeDevice.V1_0_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/PCIeDevice/PCIeDevice.V1_0_1/PCIeDevice.V1_0_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/PCIeDevice/PCIeDevice.V1_0_2/PCIeDevice.V1_0_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/PCIeDevice/PCIeDevice.V1_0_3/PCIeDevice.V1_0_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/PCIeDevice/PCIeDevice.V1_1_0/PCIeDevice.V1_1_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/PCIeDevice/PCIeDevice.V1_1_1/PCIeDevice.V1_1_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/PCIeDevice/PCIeDevice.V1_2_0/PCIeDevice.V1_2_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/PCIeDevice/PCIeDevice.V1_2_1/PCIeDevice.V1_2_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/PCIeDevice/PCIeDevice.V1_3_0/PCIeDevice.V1_3_0.c
)

file(GLOB REDFISH_JSON_CS_PCIEFUNCTION_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/PCIeFunction/PCIeFunction.V1_0_0/PCIeFunction.V1_0_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/PCIeFunction/PCIeFunction.V1_0_1/PCIeFunction.V1_0_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/PCIeFunction/PCIeFunction.V1_0_2/PCIeFunction.V1_0_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/PCIeFunction/PCIeFunction.V1_0_3/PCIeFunction.V1_0_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/PCIeFunction/PCIeFunction.V1_0_4/PCIeFunction.V1_0_4.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/PCIeFunction/PCIeFunction.V1_1_0/PCIeFunction.V1_1_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/PCIeFunction/PCIeFunction.V1_1_1/PCIeFunction.V1_1_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/PCIeFunction/PCIeFunction.V1_1_2/PCIeFunction.V1_1_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/PCIeFunction/PCIeFunction.V1_2_0/PCIeFunction.V1_2_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/PCIeFunction/PCIeFunction.V1_2_1/PCIeFunction.V1_2_1.c
)

file(GLOB REDFISH_JSON_CS_PCIESLOTS_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/PCIeSlots/PCIeSlots.V1_0_0/PCIeSlots.V1_0_0.c
)

file(GLOB REDFISH_JSON_CS_PORT_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Port/Port.V1_0_0/Port.V1_0_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Port/Port.V1_0_1/Port.V1_0_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Port/Port.V1_0_2/Port.V1_0_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Port/Port.V1_0_3/Port.V1_0_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Port/Port.V1_0_4/Port.V1_0_4.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Port/Port.V1_1_0/Port.V1_1_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Port/Port.V1_1_1/Port.V1_1_1.c
)

file(GLOB REDFISH_JSON_CS_PORTCOLLECTION_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/PortCollection/PortCollection/PortCollection.c
)

file(GLOB REDFISH_JSON_CS_POWER_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Power/Power.V1_0_0/Power.V1_0_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Power/Power.V1_0_1/Power.V1_0_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Power/Power.V1_0_2/Power.V1_0_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Power/Power.V1_0_3/Power.V1_0_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Power/Power.V1_0_4/Power.V1_0_4.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Power/Power.V1_0_5/Power.V1_0_5.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Power/Power.V1_0_6/Power.V1_0_6.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Power/Power.V1_0_7/Power.V1_0_7.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Power/Power.V1_0_8/Power.V1_0_8.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Power/Power.V1_1_0/Power.V1_1_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Power/Power.V1_1_1/Power.V1_1_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Power/Power.V1_1_2/Power.V1_1_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Power/Power.V1_1_3/Power.V1_1_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Power/Power.V1_1_4/Power.V1_1_4.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Power/Power.V1_1_5/Power.V1_1_5.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Power/Power.V1_1_6/Power.V1_1_6.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Power/Power.V1_2_0/Power.V1_2_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Power/Power.V1_2_1/Power.V1_2_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Power/Power.V1_2_2/Power.V1_2_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Power/Power.V1_2_3/Power.V1_2_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Power/Power.V1_2_4/Power.V1_2_4.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Power/Power.V1_2_5/Power.V1_2_5.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Power/Power.V1_2_6/Power.V1_2_6.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Power/Power.V1_3_0/Power.V1_3_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Power/Power.V1_3_1/Power.V1_3_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Power/Power.V1_3_2/Power.V1_3_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Power/Power.V1_3_3/Power.V1_3_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Power/Power.V1_3_4/Power.V1_3_4.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Power/Power.V1_4_0/Power.V1_4_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Power/Power.V1_4_1/Power.V1_4_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Power/Power.V1_4_2/Power.V1_4_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Power/Power.V1_4_3/Power.V1_4_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Power/Power.V1_5_0/Power.V1_5_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Power/Power.V1_5_1/Power.V1_5_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Power/Power.V1_5_2/Power.V1_5_2.c
)

file(GLOB REDFISH_JSON_CS_PRIVILEGEREGISTRY_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/PrivilegeRegistry/PrivilegeRegistry.V1_0_0/PrivilegeRegistry.V1_0_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/PrivilegeRegistry/PrivilegeRegistry.V1_0_1/PrivilegeRegistry.V1_0_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/PrivilegeRegistry/PrivilegeRegistry.V1_0_2/PrivilegeRegistry.V1_0_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/PrivilegeRegistry/PrivilegeRegistry.V1_0_3/PrivilegeRegistry.V1_0_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/PrivilegeRegistry/PrivilegeRegistry.V1_1_0/PrivilegeRegistry.V1_1_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/PrivilegeRegistry/PrivilegeRegistry.V1_1_1/PrivilegeRegistry.V1_1_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/PrivilegeRegistry/PrivilegeRegistry.V1_1_2/PrivilegeRegistry.V1_1_2.c
)

file(GLOB REDFISH_JSON_CS_PROCESSOR_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Processor/Processor.V1_0_0/Processor.V1_0_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Processor/Processor.V1_0_2/Processor.V1_0_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Processor/Processor.V1_0_3/Processor.V1_0_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Processor/Processor.V1_0_4/Processor.V1_0_4.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Processor/Processor.V1_0_5/Processor.V1_0_5.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Processor/Processor.V1_0_6/Processor.V1_0_6.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Processor/Processor.V1_1_0/Processor.V1_1_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Processor/Processor.V1_1_1/Processor.V1_1_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Processor/Processor.V1_1_2/Processor.V1_1_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Processor/Processor.V1_2_0/Processor.V1_2_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Processor/Processor.V1_2_1/Processor.V1_2_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Processor/Processor.V1_2_2/Processor.V1_2_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Processor/Processor.V1_3_0/Processor.V1_3_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Processor/Processor.V1_3_1/Processor.V1_3_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Processor/Processor.V1_3_2/Processor.V1_3_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Processor/Processor.V1_4_0/Processor.V1_4_0.c
)

file(GLOB REDFISH_JSON_CS_PROCESSORCOLLECTION_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ProcessorCollection/ProcessorCollection/ProcessorCollection.c
)

file(GLOB REDFISH_JSON_CS_RESOURCEBLOCK_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ResourceBlock/ResourceBlock.V1_0_0/ResourceBlock.V1_0_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ResourceBlock/ResourceBlock.V1_0_1/ResourceBlock.V1_0_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ResourceBlock/ResourceBlock.V1_0_2/ResourceBlock.V1_0_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ResourceBlock/ResourceBlock.V1_1_0/ResourceBlock.V1_1_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ResourceBlock/ResourceBlock.V1_1_1/ResourceBlock.V1_1_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ResourceBlock/ResourceBlock.V1_1_2/ResourceBlock.V1_1_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ResourceBlock/ResourceBlock.V1_2_0/ResourceBlock.V1_2_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ResourceBlock/ResourceBlock.V1_2_1/ResourceBlock.V1_2_1.c
)

file(GLOB REDFISH_JSON_CS_RESOURCEBLOCKCOLLECTION_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ResourceBlockCollection/ResourceBlockCollection/ResourceBlockCollection.c
)

file(GLOB REDFISH_JSON_CS_ROLE_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Role/Role.V1_0_0/Role.V1_0_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Role/Role.V1_0_2/Role.V1_0_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Role/Role.V1_0_3/Role.V1_0_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Role/Role.V1_0_4/Role.V1_0_4.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Role/Role.V1_1_0/Role.V1_1_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Role/Role.V1_1_1/Role.V1_1_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Role/Role.V1_1_2/Role.V1_1_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Role/Role.V1_2_0/Role.V1_2_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Role/Role.V1_2_1/Role.V1_2_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Role/Role.V1_2_2/Role.V1_2_2.c
)

file(GLOB REDFISH_JSON_CS_ROLECOLLECTION_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/RoleCollection/RoleCollection/RoleCollection.c
)

file(GLOB REDFISH_JSON_CS_SECUREBOOT_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/SecureBoot/SecureBoot.V1_0_0/SecureBoot.V1_0_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/SecureBoot/SecureBoot.V1_0_1/SecureBoot.V1_0_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/SecureBoot/SecureBoot.V1_0_2/SecureBoot.V1_0_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/SecureBoot/SecureBoot.V1_0_3/SecureBoot.V1_0_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/SecureBoot/SecureBoot.V1_0_4/SecureBoot.V1_0_4.c
)

file(GLOB REDFISH_JSON_CS_SERIALINTERFACE_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/SerialInterface/SerialInterface.V1_0_0/SerialInterface.V1_0_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/SerialInterface/SerialInterface.V1_0_2/SerialInterface.V1_0_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/SerialInterface/SerialInterface.V1_0_3/SerialInterface.V1_0_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/SerialInterface/SerialInterface.V1_0_4/SerialInterface.V1_0_4.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/SerialInterface/SerialInterface.V1_0_5/SerialInterface.V1_0_5.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/SerialInterface/SerialInterface.V1_0_6/SerialInterface.V1_0_6.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/SerialInterface/SerialInterface.V1_1_0/SerialInterface.V1_1_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/SerialInterface/SerialInterface.V1_1_1/SerialInterface.V1_1_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/SerialInterface/SerialInterface.V1_1_2/SerialInterface.V1_1_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/SerialInterface/SerialInterface.V1_1_3/SerialInterface.V1_1_3.c
)

file(GLOB REDFISH_JSON_CS_SERIALINTERFACECOLLECTION_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/SerialInterfaceCollection/SerialInterfaceCollection/SerialInterfaceCollection.c
)

file(GLOB REDFISH_JSON_CS_SERVICEROOT_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ServiceRoot/ServiceRoot.V1_0_0/ServiceRoot.V1_0_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ServiceRoot/ServiceRoot.V1_0_2/ServiceRoot.V1_0_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ServiceRoot/ServiceRoot.V1_0_3/ServiceRoot.V1_0_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ServiceRoot/ServiceRoot.V1_0_4/ServiceRoot.V1_0_4.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ServiceRoot/ServiceRoot.V1_0_5/ServiceRoot.V1_0_5.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ServiceRoot/ServiceRoot.V1_0_6/ServiceRoot.V1_0_6.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ServiceRoot/ServiceRoot.V1_0_7/ServiceRoot.V1_0_7.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ServiceRoot/ServiceRoot.V1_1_0/ServiceRoot.V1_1_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ServiceRoot/ServiceRoot.V1_1_1/ServiceRoot.V1_1_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ServiceRoot/ServiceRoot.V1_1_2/ServiceRoot.V1_1_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ServiceRoot/ServiceRoot.V1_1_3/ServiceRoot.V1_1_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ServiceRoot/ServiceRoot.V1_1_4/ServiceRoot.V1_1_4.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ServiceRoot/ServiceRoot.V1_2_0/ServiceRoot.V1_2_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ServiceRoot/ServiceRoot.V1_2_1/ServiceRoot.V1_2_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ServiceRoot/ServiceRoot.V1_2_2/ServiceRoot.V1_2_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ServiceRoot/ServiceRoot.V1_3_0/ServiceRoot.V1_3_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ServiceRoot/ServiceRoot.V1_3_1/ServiceRoot.V1_3_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ServiceRoot/ServiceRoot.V1_3_2/ServiceRoot.V1_3_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ServiceRoot/ServiceRoot.V1_3_3/ServiceRoot.V1_3_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ServiceRoot/ServiceRoot.V1_4_0/ServiceRoot.V1_4_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ServiceRoot/ServiceRoot.V1_4_1/ServiceRoot.V1_4_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ServiceRoot/ServiceRoot.V1_5_0/ServiceRoot.V1_5_0.c
)

file(GLOB REDFISH_JSON_CS_SESSION_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Session/Session.V1_0_0/Session.V1_0_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Session/Session.V1_0_2/Session.V1_0_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Session/Session.V1_0_3/Session.V1_0_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Session/Session.V1_0_4/Session.V1_0_4.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Session/Session.V1_1_0/Session.V1_1_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Session/Session.V1_1_1/Session.V1_1_1.c
)

file(GLOB REDFISH_JSON_CS_SESSIONCOLLECTION_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/SessionCollection/SessionCollection/SessionCollection.c
)

file(GLOB REDFISH_JSON_CS_SESSIONSERVICE_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/SessionService/SessionService.V1_0_0/SessionService.V1_0_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/SessionService/SessionService.V1_0_2/SessionService.V1_0_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/SessionService/SessionService.V1_0_3/SessionService.V1_0_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/SessionService/SessionService.V1_0_4/SessionService.V1_0_4.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/SessionService/SessionService.V1_0_5/SessionService.V1_0_5.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/SessionService/SessionService.V1_1_0/SessionService.V1_1_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/SessionService/SessionService.V1_1_1/SessionService.V1_1_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/SessionService/SessionService.V1_1_2/SessionService.V1_1_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/SessionService/SessionService.V1_1_3/SessionService.V1_1_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/SessionService/SessionService.V1_1_4/SessionService.V1_1_4.c
)

file(GLOB REDFISH_JSON_CS_SIMPLESTORAGE_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/SimpleStorage/SimpleStorage.V1_0_0/SimpleStorage.V1_0_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/SimpleStorage/SimpleStorage.V1_0_2/SimpleStorage.V1_0_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/SimpleStorage/SimpleStorage.V1_0_3/SimpleStorage.V1_0_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/SimpleStorage/SimpleStorage.V1_0_4/SimpleStorage.V1_0_4.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/SimpleStorage/SimpleStorage.V1_0_5/SimpleStorage.V1_0_5.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/SimpleStorage/SimpleStorage.V1_1_0/SimpleStorage.V1_1_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/SimpleStorage/SimpleStorage.V1_1_1/SimpleStorage.V1_1_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/SimpleStorage/SimpleStorage.V1_1_2/SimpleStorage.V1_1_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/SimpleStorage/SimpleStorage.V1_1_3/SimpleStorage.V1_1_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/SimpleStorage/SimpleStorage.V1_2_0/SimpleStorage.V1_2_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/SimpleStorage/SimpleStorage.V1_2_1/SimpleStorage.V1_2_1.c
)

file(GLOB REDFISH_JSON_CS_SIMPLESTORAGECOLLECTION_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/SimpleStorageCollection/SimpleStorageCollection/SimpleStorageCollection.c
)

file(GLOB REDFISH_JSON_CS_SOFTWAREINVENTORY_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/SoftwareInventory/SoftwareInventory.V1_0_0/SoftwareInventory.V1_0_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/SoftwareInventory/SoftwareInventory.V1_0_1/SoftwareInventory.V1_0_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/SoftwareInventory/SoftwareInventory.V1_0_2/SoftwareInventory.V1_0_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/SoftwareInventory/SoftwareInventory.V1_0_3/SoftwareInventory.V1_0_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/SoftwareInventory/SoftwareInventory.V1_1_0/SoftwareInventory.V1_1_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/SoftwareInventory/SoftwareInventory.V1_1_1/SoftwareInventory.V1_1_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/SoftwareInventory/SoftwareInventory.V1_1_2/SoftwareInventory.V1_1_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/SoftwareInventory/SoftwareInventory.V1_2_0/SoftwareInventory.V1_2_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/SoftwareInventory/SoftwareInventory.V1_2_1/SoftwareInventory.V1_2_1.c
)

file(GLOB REDFISH_JSON_CS_SOFTWAREINVENTORYCOLLECTION_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/SoftwareInventoryCollection/SoftwareInventoryCollection/SoftwareInventoryCollection.c
)

file(GLOB REDFISH_JSON_CS_STORAGE_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Storage/Storage.V1_0_1/Storage.V1_0_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Storage/Storage.V1_0_2/Storage.V1_0_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Storage/Storage.V1_0_3/Storage.V1_0_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Storage/Storage.V1_0_4/Storage.V1_0_4.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Storage/Storage.V1_0_5/Storage.V1_0_5.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Storage/Storage.V1_0_6/Storage.V1_0_6.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Storage/Storage.V1_1_1/Storage.V1_1_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Storage/Storage.V1_1_2/Storage.V1_1_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Storage/Storage.V1_1_3/Storage.V1_1_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Storage/Storage.V1_1_4/Storage.V1_1_4.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Storage/Storage.V1_1_5/Storage.V1_1_5.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Storage/Storage.V1_2_0/Storage.V1_2_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Storage/Storage.V1_2_1/Storage.V1_2_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Storage/Storage.V1_2_2/Storage.V1_2_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Storage/Storage.V1_2_3/Storage.V1_2_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Storage/Storage.V1_3_0/Storage.V1_3_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Storage/Storage.V1_3_1/Storage.V1_3_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Storage/Storage.V1_3_2/Storage.V1_3_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Storage/Storage.V1_3_3/Storage.V1_3_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Storage/Storage.V1_4_0/Storage.V1_4_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Storage/Storage.V1_4_1/Storage.V1_4_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Storage/Storage.V1_4_2/Storage.V1_4_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Storage/Storage.V1_5_0/Storage.V1_5_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Storage/Storage.V1_5_1/Storage.V1_5_1.c
)

file(GLOB REDFISH_JSON_CS_STORAGECOLLECTION_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/StorageCollection/StorageCollection/StorageCollection.c
)

file(GLOB REDFISH_JSON_CS_SWITCH_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Switch/Switch.V1_0_0/Switch.V1_0_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Switch/Switch.V1_0_1/Switch.V1_0_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Switch/Switch.V1_0_2/Switch.V1_0_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Switch/Switch.V1_0_3/Switch.V1_0_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Switch/Switch.V1_0_4/Switch.V1_0_4.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Switch/Switch.V1_1_0/Switch.V1_1_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Switch/Switch.V1_1_1/Switch.V1_1_1.c
)

file(GLOB REDFISH_JSON_CS_SWITCHCOLLECTION_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/SwitchCollection/SwitchCollection/SwitchCollection.c
)

file(GLOB REDFISH_JSON_CS_TASK_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Task/Task.V1_0_0/Task.V1_0_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Task/Task.V1_0_2/Task.V1_0_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Task/Task.V1_0_3/Task.V1_0_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Task/Task.V1_0_4/Task.V1_0_4.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Task/Task.V1_0_5/Task.V1_0_5.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Task/Task.V1_0_6/Task.V1_0_6.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Task/Task.V1_1_0/Task.V1_1_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Task/Task.V1_1_1/Task.V1_1_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Task/Task.V1_1_2/Task.V1_1_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Task/Task.V1_1_3/Task.V1_1_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Task/Task.V1_2_0/Task.V1_2_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Task/Task.V1_2_1/Task.V1_2_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Task/Task.V1_2_2/Task.V1_2_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Task/Task.V1_3_0/Task.V1_3_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Task/Task.V1_3_1/Task.V1_3_1.c
)

file(GLOB REDFISH_JSON_CS_TASKCOLLECTION_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/TaskCollection/TaskCollection/TaskCollection.c
)

file(GLOB REDFISH_JSON_CS_TASKSERVICE_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/TaskService/TaskService.V1_0_0/TaskService.V1_0_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/TaskService/TaskService.V1_0_2/TaskService.V1_0_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/TaskService/TaskService.V1_0_3/TaskService.V1_0_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/TaskService/TaskService.V1_0_4/TaskService.V1_0_4.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/TaskService/TaskService.V1_0_5/TaskService.V1_0_5.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/TaskService/TaskService.V1_1_0/TaskService.V1_1_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/TaskService/TaskService.V1_1_1/TaskService.V1_1_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/TaskService/TaskService.V1_1_2/TaskService.V1_1_2.c
)

file(GLOB REDFISH_JSON_CS_TELEMETRYSERVICE_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/TelemetryService/TelemetryService.V1_0_0/TelemetryService.V1_0_0.c
)

file(GLOB REDFISH_JSON_CS_THERMAL_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Thermal/Thermal.V1_0_0/Thermal.V1_0_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Thermal/Thermal.V1_0_1/Thermal.V1_0_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Thermal/Thermal.V1_0_2/Thermal.V1_0_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Thermal/Thermal.V1_0_3/Thermal.V1_0_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Thermal/Thermal.V1_0_4/Thermal.V1_0_4.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Thermal/Thermal.V1_0_5/Thermal.V1_0_5.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Thermal/Thermal.V1_0_6/Thermal.V1_0_6.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Thermal/Thermal.V1_0_7/Thermal.V1_0_7.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Thermal/Thermal.V1_0_8/Thermal.V1_0_8.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Thermal/Thermal.V1_1_0/Thermal.V1_1_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Thermal/Thermal.V1_1_1/Thermal.V1_1_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Thermal/Thermal.V1_1_2/Thermal.V1_1_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Thermal/Thermal.V1_1_3/Thermal.V1_1_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Thermal/Thermal.V1_1_4/Thermal.V1_1_4.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Thermal/Thermal.V1_1_5/Thermal.V1_1_5.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Thermal/Thermal.V1_1_6/Thermal.V1_1_6.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Thermal/Thermal.V1_2_0/Thermal.V1_2_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Thermal/Thermal.V1_2_1/Thermal.V1_2_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Thermal/Thermal.V1_2_2/Thermal.V1_2_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Thermal/Thermal.V1_2_3/Thermal.V1_2_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Thermal/Thermal.V1_2_4/Thermal.V1_2_4.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Thermal/Thermal.V1_2_5/Thermal.V1_2_5.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Thermal/Thermal.V1_3_0/Thermal.V1_3_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Thermal/Thermal.V1_3_1/Thermal.V1_3_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Thermal/Thermal.V1_3_2/Thermal.V1_3_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Thermal/Thermal.V1_3_3/Thermal.V1_3_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Thermal/Thermal.V1_3_4/Thermal.V1_3_4.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Thermal/Thermal.V1_4_0/Thermal.V1_4_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Thermal/Thermal.V1_4_1/Thermal.V1_4_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Thermal/Thermal.V1_4_2/Thermal.V1_4_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Thermal/Thermal.V1_5_0/Thermal.V1_5_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Thermal/Thermal.V1_5_1/Thermal.V1_5_1.c
)

file(GLOB REDFISH_JSON_CS_TRIGGERS_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Triggers/Triggers.V1_0_0/Triggers.V1_0_0.c
)

file(GLOB REDFISH_JSON_CS_TRIGGERSCOLLECTION_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/TriggersCollection/TriggersCollection/TriggersCollection.c
)

file(GLOB REDFISH_JSON_CS_UPDATESERVICE_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/UpdateService/UpdateService.V1_0_0/UpdateService.V1_0_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/UpdateService/UpdateService.V1_0_1/UpdateService.V1_0_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/UpdateService/UpdateService.V1_0_2/UpdateService.V1_0_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/UpdateService/UpdateService.V1_0_3/UpdateService.V1_0_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/UpdateService/UpdateService.V1_0_4/UpdateService.V1_0_4.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/UpdateService/UpdateService.V1_0_5/UpdateService.V1_0_5.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/UpdateService/UpdateService.V1_1_0/UpdateService.V1_1_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/UpdateService/UpdateService.V1_1_1/UpdateService.V1_1_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/UpdateService/UpdateService.V1_1_2/UpdateService.V1_1_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/UpdateService/UpdateService.V1_1_3/UpdateService.V1_1_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/UpdateService/UpdateService.V1_1_4/UpdateService.V1_1_4.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/UpdateService/UpdateService.V1_2_0/UpdateService.V1_2_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/UpdateService/UpdateService.V1_2_1/UpdateService.V1_2_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/UpdateService/UpdateService.V1_2_2/UpdateService.V1_2_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/UpdateService/UpdateService.V1_2_3/UpdateService.V1_2_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/UpdateService/UpdateService.V1_3_0/UpdateService.V1_3_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/UpdateService/UpdateService.V1_3_1/UpdateService.V1_3_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/UpdateService/UpdateService.V1_4_0/UpdateService.V1_4_0.c
)

file(GLOB REDFISH_JSON_CS_VLANNETWORKINTERFACE_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/VLanNetworkInterface/VLanNetworkInterface.V1_0_0/VLanNetworkInterface.V1_0_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/VLanNetworkInterface/VLanNetworkInterface.V1_0_1/VLanNetworkInterface.V1_0_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/VLanNetworkInterface/VLanNetworkInterface.V1_0_2/VLanNetworkInterface.V1_0_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/VLanNetworkInterface/VLanNetworkInterface.V1_0_3/VLanNetworkInterface.V1_0_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/VLanNetworkInterface/VLanNetworkInterface.V1_0_4/VLanNetworkInterface.V1_0_4.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/VLanNetworkInterface/VLanNetworkInterface.V1_0_5/VLanNetworkInterface.V1_0_5.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/VLanNetworkInterface/VLanNetworkInterface.V1_0_6/VLanNetworkInterface.V1_0_6.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/VLanNetworkInterface/VLanNetworkInterface.V1_1_0/VLanNetworkInterface.V1_1_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/VLanNetworkInterface/VLanNetworkInterface.V1_1_1/VLanNetworkInterface.V1_1_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/VLanNetworkInterface/VLanNetworkInterface.V1_1_2/VLanNetworkInterface.V1_1_2.c
)

file(GLOB REDFISH_JSON_CS_VLANNETWORKINTERFACECOLLECTION_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/VLanNetworkInterfaceCollection/VLanNetworkInterfaceCollection/VLanNetworkInterfaceCollection.c
)

file(GLOB REDFISH_JSON_CS_VIRTUALMEDIA_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/VirtualMedia/VirtualMedia.V1_0_0/VirtualMedia.V1_0_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/VirtualMedia/VirtualMedia.V1_0_2/VirtualMedia.V1_0_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/VirtualMedia/VirtualMedia.V1_0_3/VirtualMedia.V1_0_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/VirtualMedia/VirtualMedia.V1_0_4/VirtualMedia.V1_0_4.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/VirtualMedia/VirtualMedia.V1_0_5/VirtualMedia.V1_0_5.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/VirtualMedia/VirtualMedia.V1_1_0/VirtualMedia.V1_1_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/VirtualMedia/VirtualMedia.V1_1_1/VirtualMedia.V1_1_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/VirtualMedia/VirtualMedia.V1_1_2/VirtualMedia.V1_1_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/VirtualMedia/VirtualMedia.V1_1_3/VirtualMedia.V1_1_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/VirtualMedia/VirtualMedia.V1_2_0/VirtualMedia.V1_2_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/VirtualMedia/VirtualMedia.V1_2_1/VirtualMedia.V1_2_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/VirtualMedia/VirtualMedia.V1_2_2/VirtualMedia.V1_2_2.c
)

file(GLOB REDFISH_JSON_CS_VIRTUALMEDIACOLLECTION_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/VirtualMediaCollection/VirtualMediaCollection/VirtualMediaCollection.c
)

file(GLOB REDFISH_JSON_CS_VOLUME_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Volume/Volume.V1_0_0/Volume.V1_0_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Volume/Volume.V1_0_1/Volume.V1_0_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Volume/Volume.V1_0_2/Volume.V1_0_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Volume/Volume.V1_0_3/Volume.V1_0_3.c
)

file(GLOB REDFISH_JSON_CS_VOLUMECOLLECTION_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/VolumeCollection/VolumeCollection/VolumeCollection.c
)

file(GLOB REDFISH_JSON_CS_ZONE_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Zone/Zone.V1_0_0/Zone.V1_0_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Zone/Zone.V1_0_1/Zone.V1_0_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Zone/Zone.V1_0_2/Zone.V1_0_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Zone/Zone.V1_0_3/Zone.V1_0_3.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Zone/Zone.V1_1_0/Zone.V1_1_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Zone/Zone.V1_1_1/Zone.V1_1_1.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Zone/Zone.V1_1_2/Zone.V1_1_2.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Zone/Zone.V1_2_0/Zone.V1_2_0.c
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/Zone/Zone.V1_2_1/Zone.V1_2_1.c
)

file(GLOB REDFISH_JSON_CS_ZONECOLLECTION_SRC
    ${REDFISH_JSON_CS_LIB_SRC_ROOT}/ZoneCollection/ZoneCollection/ZoneCollection.c
)

source_group("Common Library Sources" FILES ${REDFISH_JSON_CS_LIB_SRC})

add_library(RedfishCS STATIC
     ${REDFISH_JSON_CS_LIB_SRC}
    ${REDFISH_JSON_CS_ACCOUNTSERVICE_SRC}
    ${REDFISH_JSON_CS_ACTIONINFO_SRC}
    ${REDFISH_JSON_CS_ASSEMBLY_SRC}
    ${REDFISH_JSON_CS_ATTRIBUTEREGISTRY_SRC}
    ${REDFISH_JSON_CS_BIOS_SRC}
    ${REDFISH_JSON_CS_BOOTOPTION_SRC}
    ${REDFISH_JSON_CS_BOOTOPTIONCOLLECTION_SRC}
    ${REDFISH_JSON_CS_CHASSIS_SRC}
    ${REDFISH_JSON_CS_CHASSISCOLLECTION_SRC}
    ${REDFISH_JSON_CS_COMPOSITIONSERVICE_SRC}
    ${REDFISH_JSON_CS_COMPUTERSYSTEM_SRC}
    ${REDFISH_JSON_CS_COMPUTERSYSTEMCOLLECTION_SRC}
    ${REDFISH_JSON_CS_DRIVE_SRC}
    ${REDFISH_JSON_CS_ENDPOINT_SRC}
    ${REDFISH_JSON_CS_ENDPOINTCOLLECTION_SRC}
    ${REDFISH_JSON_CS_ETHERNETINTERFACE_SRC}
    ${REDFISH_JSON_CS_ETHERNETINTERFACECOLLECTION_SRC}
    ${REDFISH_JSON_CS_EVENT_SRC}
    ${REDFISH_JSON_CS_EVENTDESTINATION_SRC}
    ${REDFISH_JSON_CS_EVENTDESTINATIONCOLLECTION_SRC}
    ${REDFISH_JSON_CS_EVENTSERVICE_SRC}
    ${REDFISH_JSON_CS_EXTERNALACCOUNTPROVIDER_SRC}
    ${REDFISH_JSON_CS_EXTERNALACCOUNTPROVIDERCOLLECTION_SRC}
    ${REDFISH_JSON_CS_FABRIC_SRC}
    ${REDFISH_JSON_CS_FABRICCOLLECTION_SRC}
    ${REDFISH_JSON_CS_HOSTINTERFACE_SRC}
    ${REDFISH_JSON_CS_HOSTINTERFACECOLLECTION_SRC}
    ${REDFISH_JSON_CS_JOB_SRC}
    ${REDFISH_JSON_CS_JOBCOLLECTION_SRC}
    ${REDFISH_JSON_CS_JOBSERVICE_SRC}
    ${REDFISH_JSON_CS_JSONSCHEMAFILE_SRC}
    ${REDFISH_JSON_CS_JSONSCHEMAFILECOLLECTION_SRC}
    ${REDFISH_JSON_CS_LOGENTRY_SRC}
    ${REDFISH_JSON_CS_LOGENTRYCOLLECTION_SRC}
    ${REDFISH_JSON_CS_LOGSERVICE_SRC}
    ${REDFISH_JSON_CS_LOGSERVICECOLLECTION_SRC}
    ${REDFISH_JSON_CS_MANAGER_SRC}
    ${REDFISH_JSON_CS_MANAGERACCOUNT_SRC}
    ${REDFISH_JSON_CS_MANAGERACCOUNTCOLLECTION_SRC}
    ${REDFISH_JSON_CS_MANAGERCOLLECTION_SRC}
    ${REDFISH_JSON_CS_MANAGERNETWORKPROTOCOL_SRC}
    ${REDFISH_JSON_CS_MEMORY_SRC}
    ${REDFISH_JSON_CS_MEMORYCHUNKS_SRC}
    ${REDFISH_JSON_CS_MEMORYCHUNKSCOLLECTION_SRC}
    ${REDFISH_JSON_CS_MEMORYCOLLECTION_SRC}
    ${REDFISH_JSON_CS_MEMORYDOMAIN_SRC}
    ${REDFISH_JSON_CS_MEMORYDOMAINCOLLECTION_SRC}
    ${REDFISH_JSON_CS_MEMORYMETRICS_SRC}
    ${REDFISH_JSON_CS_MESSAGEREGISTRY_SRC}
    ${REDFISH_JSON_CS_MESSAGEREGISTRYCOLLECTION_SRC}
    ${REDFISH_JSON_CS_MESSAGEREGISTRYFILE_SRC}
    ${REDFISH_JSON_CS_MESSAGEREGISTRYFILECOLLECTION_SRC}
    ${REDFISH_JSON_CS_METRICDEFINITION_SRC}
    ${REDFISH_JSON_CS_METRICDEFINITIONCOLLECTION_SRC}
    ${REDFISH_JSON_CS_METRICREPORT_SRC}
    ${REDFISH_JSON_CS_METRICREPORTCOLLECTION_SRC}
    ${REDFISH_JSON_CS_METRICREPORTDEFINITION_SRC}
    ${REDFISH_JSON_CS_METRICREPORTDEFINITIONCOLLECTION_SRC}
    ${REDFISH_JSON_CS_NETWORKADAPTER_SRC}
    ${REDFISH_JSON_CS_NETWORKADAPTERCOLLECTION_SRC}
    ${REDFISH_JSON_CS_NETWORKDEVICEFUNCTION_SRC}
    ${REDFISH_JSON_CS_NETWORKDEVICEFUNCTIONCOLLECTION_SRC}
    ${REDFISH_JSON_CS_NETWORKINTERFACE_SRC}
    ${REDFISH_JSON_CS_NETWORKINTERFACECOLLECTION_SRC}
    ${REDFISH_JSON_CS_NETWORKPORT_SRC}
    ${REDFISH_JSON_CS_NETWORKPORTCOLLECTION_SRC}
    ${REDFISH_JSON_CS_PCIEDEVICE_SRC}
    ${REDFISH_JSON_CS_PCIEFUNCTION_SRC}
    ${REDFISH_JSON_CS_PCIESLOTS_SRC}
    ${REDFISH_JSON_CS_PORT_SRC}
    ${REDFISH_JSON_CS_PORTCOLLECTION_SRC}
    ${REDFISH_JSON_CS_POWER_SRC}
    ${REDFISH_JSON_CS_PRIVILEGEREGISTRY_SRC}
    ${REDFISH_JSON_CS_PROCESSOR_SRC}
    ${REDFISH_JSON_CS_PROCESSORCOLLECTION_SRC}
    ${REDFISH_JSON_CS_RESOURCEBLOCK_SRC}
    ${REDFISH_JSON_CS_RESOURCEBLOCKCOLLECTION_SRC}
    ${REDFISH_JSON_CS_ROLE_SRC}
    ${REDFISH_JSON_CS_ROLECOLLECTION_SRC}
    ${REDFISH_JSON_CS_SECUREBOOT_SRC}
    ${REDFISH_JSON_CS_SERIALINTERFACE_SRC}
    ${REDFISH_JSON_CS_SERIALINTERFACECOLLECTION_SRC}
    ${REDFISH_JSON_CS_SERVICEROOT_SRC}
    ${REDFISH_JSON_CS_SESSION_SRC}
    ${REDFISH_JSON_CS_SESSIONCOLLECTION_SRC}
    ${REDFISH_JSON_CS_SESSIONSERVICE_SRC}
    ${REDFISH_JSON_CS_SIMPLESTORAGE_SRC}
    ${REDFISH_JSON_CS_SIMPLESTORAGECOLLECTION_SRC}
    ${REDFISH_JSON_CS_SOFTWAREINVENTORY_SRC}
    ${REDFISH_JSON_CS_SOFTWAREINVENTORYCOLLECTION_SRC}
    ${REDFISH_JSON_CS_STORAGE_SRC}
    ${REDFISH_JSON_CS_STORAGECOLLECTION_SRC}
    ${REDFISH_JSON_CS_SWITCH_SRC}
    ${REDFISH_JSON_CS_SWITCHCOLLECTION_SRC}
    ${REDFISH_JSON_CS_TASK_SRC}
    ${REDFISH_JSON_CS_TASKCOLLECTION_SRC}
    ${REDFISH_JSON_CS_TASKSERVICE_SRC}
    ${REDFISH_JSON_CS_TELEMETRYSERVICE_SRC}
    ${REDFISH_JSON_CS_THERMAL_SRC}
    ${REDFISH_JSON_CS_TRIGGERS_SRC}
    ${REDFISH_JSON_CS_TRIGGERSCOLLECTION_SRC}
    ${REDFISH_JSON_CS_UPDATESERVICE_SRC}
    ${REDFISH_JSON_CS_VLANNETWORKINTERFACE_SRC}
    ${REDFISH_JSON_CS_VLANNETWORKINTERFACECOLLECTION_SRC}
    ${REDFISH_JSON_CS_VIRTUALMEDIA_SRC}
    ${REDFISH_JSON_CS_VIRTUALMEDIACOLLECTION_SRC}
    ${REDFISH_JSON_CS_VOLUME_SRC}
    ${REDFISH_JSON_CS_VOLUMECOLLECTION_SRC}
    ${REDFISH_JSON_CS_ZONE_SRC}
    ${REDFISH_JSON_CS_ZONECOLLECTION_SRC}
)
if(CMAKE_COMPILER_IS_GNUCC)
add_definitions(-Wall -Wextra -Wdeclaration-after-statement -ggdb3)
endif()
