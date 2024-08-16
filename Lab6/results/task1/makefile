PRJ = HyperLCA
CC = icpx

SRCS  = Main_Compresor_HW.cpp dpcHLCA.cpp
OBJS = $(SRCS:.c=.o)


CFLAGS += -g -Wall -O1
CPPFLAGS += -I/opt/intel/oneapi/advisor/2023.2.0/include -fopenmp -fsycl
CPPFLAGS += -I/opt/intel/oneapi/compiler/2023.2.0/linux/include/sycl/CL
LDFLAGS += -D VERBOSE -D BLOCK_DBG=0


all : $(PRJ)

%.o : %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $^

$(PRJ): $(OBJS)
	$(CC) $(CPPFLAGS) $(LDFLAGS) $^ -o $@

mission.bin:
	megadl 'https://mega.nz/file/Z5JUkSoI#boptGx0TD4YU1FGz5WxVkxgB0-fav1sQiVVCk2lz_CA'

run: $(PRJ) mission.bin
	./$(PRJ)


clean:
	$(RM) -rf $(PRJ) *~ *.o compressedBitstream.bin output

cleanall: clean
	$(RM) -rf mission.bin
