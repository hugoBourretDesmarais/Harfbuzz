
# Mac Installation
arch -arm64 brew install harfbuzz

Here's how you can do it:

Navigate to your dynamic library's directory:

bash
Copy code
cd /Users/hugob/Documents/Job/Git/Harfbuzz/harfbuzz/build/src/
Use install_name_tool to change the install name of the dynamic library:

bash
Copy code
install_name_tool -id $(pwd)/libharfbuzz.0.dylib libharfbuzz.0.dylib
Then, update your binary's (main) dynamic library load path to the new absolute path of libharfbuzz.0.dylib:

bash
Copy code
install_name_tool -change @rpath/libharfbuzz.0.dylib $(pwd)/libharfbuzz.0.dylib /path/to/your/main
Now, you should be able to execute main without experiencing the Library not loaded error.