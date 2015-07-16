project(pcap-dumper)

add_executable(pcap-dumper 
main.cpp
Dumper.cpp)

install(TARGETS pcap-dumper RUNTIME DESTINATION bin)
