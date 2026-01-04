add_rules("mode.debug", "mode.release")
set_encodings("utf-8")
set_warnings("all")
set_languages("cxx17")

target("test")
    set_kind("static")
    add_defines(string.format("__XMAKE__=\"%s\"", os.scriptdir():gsub("\\", "/")))
    add_defines("_CRT_SECURE_NO_WARNINGS")
    add_files("learn/test.cpp")

target("learn")
    set_kind("binary")
    add_deps("test")
    set_languages("cxx17")
    add_defines("_CRT_SECURE_NO_WARNINGS")

    add_files("learn/learn.cpp")


target("00_hello_world")
    set_kind("binary")
    set_languages("cxx17")
    add_defines("_CRT_SECURE_NO_WARNINGS")

    add_files("exercises/00_hello_world/**.cpp")

target("01_variable&add")
    set_kind("binary")
    set_languages("cxx17")
    add_defines("_CRT_SECURE_NO_WARNINGS")

    add_files("exercises/01_variable&add/**.cpp")

target("02_function")
    set_kind("binary")
    set_languages("cxx17")
    add_defines("_CRT_SECURE_NO_WARNINGS")

    add_files("exercises/02_function/**.cpp")

target("03_argument&parameter")
    set_kind("binary")
    set_languages("cxx17")
    add_defines("_CRT_SECURE_NO_WARNINGS")

    add_files("exercises/03_argument&parameter/**.cpp")

target("04_static")
    set_kind("binary")
    set_languages("cxx17")
    add_defines("_CRT_SECURE_NO_WARNINGS")

    add_files("exercises/04_static/**.cpp")

target("05_constexpr")
    set_kind("binary")
    set_languages("cxx17")
    add_defines("_CRT_SECURE_NO_WARNINGS")

    add_files("exercises/05_constexpr/**.cpp")

target("06_array")
    set_kind("binary")
    set_languages("cxx17")
    add_defines("_CRT_SECURE_NO_WARNINGS")

    add_files("exercises/06_array/**.cpp")

target("07_loop")
    set_kind("binary")
    set_languages("cxx17")
    add_defines("_CRT_SECURE_NO_WARNINGS")

    add_files("exercises/07_loop/**.cpp")

target("08_pointer")
    set_kind("binary")
    set_languages("cxx17")
    add_defines("_CRT_SECURE_NO_WARNINGS")

    add_files("exercises/08_pointer/**.cpp")

target("09_enum&union")
    set_kind("binary")
    set_languages("cxx17")
    add_defines("_CRT_SECURE_NO_WARNINGS")

    add_files("exercises/09_enum&union/**.cpp")

target("10_trivial")
    set_kind("binary")
    set_languages("cxx17")
    add_defines("_CRT_SECURE_NO_WARNINGS")

    add_files("exercises/10_trivial/**.cpp")

target("11_method")
    set_kind("binary")
    set_languages("cxx17")
    add_defines("_CRT_SECURE_NO_WARNINGS")

    add_files("exercises/11_method/**.cpp")

target("12_method_const")
    set_kind("binary")
    set_languages("cxx17")
    add_defines("_CRT_SECURE_NO_WARNINGS")

    add_files("exercises/12_method_const/**.cpp")

target("13_class")
    set_kind("binary")
    set_languages("cxx17")
    add_defines("_CRT_SECURE_NO_WARNINGS")

    add_files("exercises/13_class/**.cpp")

target("14_class_destruct")
    set_kind("binary")
    set_languages("cxx17")
    add_defines("_CRT_SECURE_NO_WARNINGS")

    add_files("exercises/14_class_destruct/**.cpp")

target("15_class_clone")
    set_kind("binary")
    set_languages("cxx17")
    add_defines("_CRT_SECURE_NO_WARNINGS")

    add_files("exercises/15_class_clone/**.cpp")

target("16_class_move")
    set_kind("binary")
    set_languages("cxx17")
    add_defines("_CRT_SECURE_NO_WARNINGS")

    add_files("exercises/16_class_move/**.cpp")

target("17_class_derive")
    set_kind("binary")
    set_languages("cxx17")
    add_defines("_CRT_SECURE_NO_WARNINGS")

    add_files("exercises/17_class_derive/**.cpp")

target("18_class_virtual")
    set_kind("binary")
    set_languages("cxx17")
    add_defines("_CRT_SECURE_NO_WARNINGS")

    add_files("exercises/18_class_virtual/**.cpp")

target("19_class_virtual_destruct")
    set_kind("binary")
    set_languages("cxx17")
    add_defines("_CRT_SECURE_NO_WARNINGS")

    add_files("exercises/19_class_virtual_destruct/**.cpp")

target("20_function_template")
    set_kind("binary")
    set_languages("cxx17")
    add_defines("_CRT_SECURE_NO_WARNINGS")

    add_files("exercises/20_function_template/**.cpp")

target("21_runtime_datatype")
    set_kind("binary")
    set_languages("cxx17")
    add_defines("_CRT_SECURE_NO_WARNINGS")

    add_files("exercises/21_runtime_datatype/**.cpp")

target("22_class_template")
    set_kind("binary")
    set_languages("cxx17")
    add_defines("_CRT_SECURE_NO_WARNINGS")

    add_files("exercises/22_class_template/**.cpp")

target("23_template_const")
    set_kind("binary")
    set_languages("cxx17")
    add_defines("_CRT_SECURE_NO_WARNINGS")

    add_files("exercises/23_template_const/**.cpp")

target("24_std_array")
    set_kind("binary")
    set_languages("cxx17")
    add_defines("_CRT_SECURE_NO_WARNINGS")

    add_files("exercises/24_std_array/**.cpp")

target("25_std_vector")
    set_kind("binary")
    set_languages("cxx17")
    add_defines("_CRT_SECURE_NO_WARNINGS")

    add_files("exercises/25_std_vector/**.cpp")

target("26_std_vector_bool")
    set_kind("binary")
    set_languages("cxx17")
    add_defines("_CRT_SECURE_NO_WARNINGS")

    add_files("exercises/26_std_vector_bool/**.cpp")

target("27_strides")
    set_kind("binary")
    set_languages("cxx17")
    add_defines("_CRT_SECURE_NO_WARNINGS")

    add_files("exercises/27_strides/**.cpp")

target("28_std_string")
    set_kind("binary")
    set_languages("cxx17")
    add_defines("_CRT_SECURE_NO_WARNINGS")

    add_files("exercises/28_std_string/**.cpp")

target("29_std_map")
    set_kind("binary")
    set_languages("cxx17")
    add_defines("_CRT_SECURE_NO_WARNINGS")

    add_files("exercises/29_std_map/**.cpp")

target("30_std_unique_ptr")
    set_kind("binary")
    set_languages("cxx17")
    add_defines("_CRT_SECURE_NO_WARNINGS")

    add_files("exercises/30_std_unique_ptr/**.cpp")

target("31_std_shared_ptr")
    set_kind("binary")
    set_languages("cxx17")
    add_defines("_CRT_SECURE_NO_WARNINGS")

    add_files("exercises/31_std_shared_ptr/**.cpp")

target("32_std_transform")
    set_kind("binary")
    set_languages("cxx17")
    add_defines("_CRT_SECURE_NO_WARNINGS")

    add_files("exercises/32_std_transform/**.cpp")


target("33_std_accumulate")
    set_kind("binary")
    set_languages("cxx17")
    add_defines("_CRT_SECURE_NO_WARNINGS")

    add_files("exercises/33_std_accumulate/**.cpp")


target("summary")
    set_kind("binary")
    add_deps("test")
    add_defines("_CRT_SECURE_NO_WARNINGS")
    add_files("learn/summary.cpp")