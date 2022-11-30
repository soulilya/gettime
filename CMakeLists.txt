cmake_minimum_required(VERSION 3.17)
project(gettime
	VERSION 1.0
	DESCRIPTION "Function for MACOS instead clock_gettime"
	LANGUAGES C)
add_library(gettime SHARED gettime.c)
set_target_properties(gettime PROPERTIES VERSION ${PROJECT_VERSION}
				SOVERSION 1
 				PUBLIC_HEADER gettime.h)
include(GNUInstallDirs)
configure_file(gettime.pc.in gettime.pc @ONLY)
install(TARGETS gettime
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
	PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(FILES ${CMAKE_BINARY_DIR}/gettime.pc
	DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)
