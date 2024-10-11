FROM ubuntu:latest

# install g++ gdb
RUN apt-get update && apt-get install -y \
    g++ \
    gdb \
    && rm -rf /var/lib/apt/lists/*

# set workspace
WORKDIR /OnlineJudge

CMD ["/bin/bash"]
