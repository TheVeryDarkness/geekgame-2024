FROM debian:12

RUN apt update && apt install -y \
    git python3 python3-tk python3-pil python3-pil.imagetk \
    build-essential cmake libsdl2-dev qt6-base-dev \
    libminizip-dev zlib1g-dev libgl1-mesa-dev

WORKDIR /root
RUN git clone https://github.com/TASEmulators/fceux.git

COPY *.py *.lua *.nes *.diff .
RUN cd fceux && git checkout v2.6.6 && git apply ../fceux-v2.6.6-patch.diff && \
  mkdir build && cd build && cmake -DCMAKE_BUILD_TYPE=Release -DQT6=1 .. && make -j

RUN echo 'fake{get flag1 on the real server}' > /flag1
RUN echo 'fake{get flag2 on the real server}' > /flag2
RUN echo 'fake{get flag3 on the real server}' > /flag3

# Execute the following command to run the judge.
#   python3 judge.py 1 your-input.bin
#   python3 judge.py 2 your-input.bin
#   python3 judge.py 3 your-input.bin your-mem-dump.bin
# X11 required.
