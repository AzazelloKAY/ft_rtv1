cmake_minimum_required(VERSION 3.9)
project(ft_rtv1 C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lmlx -lm -framework OpenGL -framework AppKit")

add_executable(ft_rtv1 sources/main.c sources/ft_rtv1.h sources/rt_sphere.c sources/ft_functions.c sources/vc_vector_func1.c sources/vc_vector_func2.c sources/ft_vector.h sources/ft_img.h sources/ft_img.c sources/ft_img_keyhook.c sources/ft_img_init_destr.c sources/vc_cam_code.c)

link_directories(libft sources)

target_link_libraries(ft_rtv1 ${CMAKE_SOURCE_DIR}/libft/libft.a)