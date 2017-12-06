Prerequisites:
 - cmake 3.5.1 (maybe works with older, but not tested)
 - RTI Connext DDS 5.3.0
 - $NDDSHOME has to be set to the root directory of RTI Connext (in the default case this is */rti_connext_dds-5.3.0/)
 - Linux x64 OS

To build you have to execute the following commands from the root directory of the repo:
```
mkdir Weather/common
${NDDSHOME}/bin/rtiddsgen  -language C++11 -stl -ppDisable -d Weather/common -replace idl_files/Weather.idl
cmake .
cmake --build .
```

After that, copy the license file to `bin`. Once the license has been copied, the subscriber can be started with `bin/cps_main s` and the publisher with `bin/cps_main p`. 

Good luck, have fun!

 
