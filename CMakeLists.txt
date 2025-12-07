cmake_minimum_required(VERSION 4.1)
project(habr_bootloader C)

# Настройка для целевой системы (bare metal)
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR mips)

# Установка компилятора и линкера
set(CMAKE_C_COMPILER "clang")
set(CMAKE_C_FLAGS "-target mipsel-elf32 -nostdlib -ffreestanding")
set(CMAKE_C_STANDARD_LIBRARIES "")

# Указываем, в какую директорию класть выполняемые файлы 
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Подключаем два проекта app (app/CMakeLists.txt), bootloader (bootloader/CMakeLists.txt) 
add_subdirectory(app)
add_subdirectory(bootloader)
