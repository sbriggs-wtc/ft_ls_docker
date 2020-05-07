FROM debian
LABEL maintainer="sbriggs"
RUN apt-get update 
RUN apt-get upgrade --yes 
#RUN apt-get install --yes vim gcc git make
RUN apt-get install -y build-essential
RUN apt-get install -y valgrind
#the valgrind install is newly added and untested

RUN mkdir /foo_workspace

#ADD ./copy_by_dockerfile /copy_by_dockerfile
#CMD /bin/bash

ENTRYPOINT /bin/bash

#docker build --tag debian_c .
#docker run -it --rm --name foobar debian_c


# temp (might not be temp anymore) -> docker run -it --rm --mount type=bind,source=D:\Users\briggss\Desktop\docker,destination=/foo_workspace --name foobar debian_c
#cd "C:\Program Files\Docker\Docker" ./DockerCli.exe -SwitchDaemon //this is for switching between linux and windows containers on a windows machine.
# apt-cache search valgrind

#docker run -it --mount type=bind,source=/d/Users/briggss/Desktop/docker/docker1,destination=/foo_workspace --name foobar debian_c
#run like above in gitbash, note directory and slashes

#valgrind --leak-check=full ./a.out (you can add -v)