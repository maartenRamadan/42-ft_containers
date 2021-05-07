TARGET1 = test1
TARGET2 = test2

SRCS1 =\
	0_main.cpp\
	1_Bidirectionaliterator_test.cpp\
	2_RandomAccessIterator_test.cpp\
	3_list_test.cpp\
	4_vector_test.cpp\
	5_queue_test.cpp\
	6_stack_test.cpp\
	7_map_test.cpp\
	catch.cpp

SRCS2 =\
	main.cpp\
	list_test.cpp\
	vector_test.cpp\
	Queue_test.cpp\
	Stack_test.cpp\
	BidirectionalIterator_test.cpp\
	RandomAccesIterator_test.cpp\
	catch.cpp

SRCS_DIR1 = UNIT_TEST1
SRCS_DIR2 = UNIT_TEST2

OBJS_DIR1 = UNIT_TEST1/build
OBJS_DIR2 = UNIT_TEST2/build

FLAGS = -std=c++14

CXX = clang++

OBJS1 = $(SRCS1:.cpp=.o)
OBJS2 = $(SRCS2:.cpp=.o)

.PHONY: all clean fclean re

all: $(TARGET1) $(TARGET2)

$(TARGET1): $(addprefix $(OBJS_DIR1)/,$(OBJS1))
	$(CXX) $(FLAGS) $(addprefix $(OBJS_DIR1)/,$(OBJS1)) -o $@

$(OBJS_DIR1)/%.o: $(SRCS_DIR1)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(FLAGS) -o $@ -c $<

$(TARGET2): $(addprefix $(OBJS_DIR2)/,$(OBJS2))
	$(CXX) $(FLAGS) $(addprefix $(OBJS_DIR2)/,$(OBJS2)) -o $@

$(OBJS_DIR2)/%.o: $(SRCS_DIR2)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(FLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJS_DIR1) $(OBJS_DIR2)

fclean: clean
	/bin/rm -f $(TARGET1) $(TARGET2)

re: fclean all