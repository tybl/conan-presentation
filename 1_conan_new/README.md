# Conan Quick Start
1. `conan new cmake_exe -d name="example-project" -d version="0.1.0"
2. Look at generated files
3. `conan build .`
4. Figure out why it didn't work for anyone else
   1. Conan profiles/Settings
5. Try builds with different settings
   1. `conan build . --settings=build_type=Debug`
5. Review pretty output
