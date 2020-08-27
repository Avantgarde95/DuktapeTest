#include <duktape.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

static duk_ret_t jsPrint(duk_context *context) {
    duk_push_string(context, " ");
    duk_insert(context, 0);
    duk_join(context, duk_get_top(context) - 1);
    std::cout << duk_safe_to_string(context, -1);
    return 0;
}

static std::string readFile(const std::string &path) {
    std::ifstream fileStream(path);

    if (fileStream.fail()) {
        throw std::runtime_error("Failed to read the file: " + path);
    }

    std::stringstream stringStream;
    stringStream << fileStream.rdbuf();
    return stringStream.str();
}

static std::string runCode(duk_context *jsContext, const std::string &code) {
    duk_push_string(jsContext, code.c_str());

    if (duk_peval(jsContext) != 0) {
        throw std::runtime_error(
                std::string("Failed to run the code: ")
                + duk_safe_to_string(jsContext, -1)
        );
    }

    std::string result = duk_safe_to_string(jsContext, -1);
    duk_pop(jsContext);
    return result;
}

int main() {
    auto jsContext = duk_create_heap_default();

    duk_push_c_function(jsContext, jsPrint, DUK_VARARGS);
    duk_put_global_string(jsContext, "print");

    try {
        runCode(jsContext, readFile("dist/bundle.js"));
    } catch (const std::runtime_error &error) {
        std::cout << "[Error] " << error.what() << "\n";
    }

    duk_destroy_heap(jsContext);

    return 0;
}
