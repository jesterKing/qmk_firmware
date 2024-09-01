# Build with: docker build -f Dockerfile -t jesterqmk .
# Run with docker run -it -v .:/qmk/local jesterqmk
# Resulting  firmware will be on the host machine once ready
FROM ubuntu:22.04

RUN apt-get update

RUN apt-get install -y avrdude binutils-arm-none-eabi binutils-riscv64-unknown-elf build-essential ca-certificates clang-format-11 dfu-programmer dfu-util dos2unix ca-certificates gcc gcc-arm-none-eabi gcc-riscv64-unknown-elf git libfl2 libnewlib-arm-none-eabi picolibc-riscv64-unknown-elf python3 python3-pip software-properties-common tar teensy-loader-cli unzip tar wget zip byobu htop

RUN python3 -m pip install qmk

VOLUME [ "/qmk/local" ]
WORKDIR /qmk
RUN git clone --recursive https://github.com/jesterKing/qmk_firmware
WORKDIR /qmk/qmk_firmware
RUN git checkout jesterking_liatris
RUN git submodule update --init --recursive

#ENTRYPOINT [ "bash" ]

CMD [ "bash", "-c", "/qmk/local/build_jesterKing.sh" ]
