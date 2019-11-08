cmake_minimum_required(VERSION 3.0)

project(bmicxx CXX)

set(BMI_VERSION 2.0)

configure_file(${CMAKE_SOURCE_DIR}/${CMAKE_PROJECT_NAME}.pc.cmake
  ${CMAKE_BINARY_DIR}/${CMAKE_PROJECT_NAME}.pc)

install(
  FILES bmi.hxx
  DESTINATION include
)
install(
  FILES ${CMAKE_BINARY_DIR}/${CMAKE_PROJECT_NAME}.pc
  DESTINATION lib/pkgconfig
)
