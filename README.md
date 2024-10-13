# OnlineJudge

浅浅记录一下刷过的题目，逻辑尽可能保证清晰。

## docker 环境搭建

构建镜像：
```sh
docker build -t onlinejudge .
```

第一次运行容器
```sh
docker run -d --name onlinejudge -ti -v ~/Projects/OnlineJudge:/OnlineJudge --cap-add=SYS_PTRACE --security-opt seccomp=unconfined onlinejudge
```

运行容器
```sh
docker start onlinejudge
```