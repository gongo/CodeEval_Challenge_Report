SRCS_DIR = src
SRCS     = $(wildcard $(SRCS_DIR)/*.cc)
TARGET   = $(notdir $(basename $(SRCS)))

TEST_DIR = test

CXXFLAGS  = -Wall -O2
CXX       = g++
RM        = rm -rf
RM_GC     = *~ \#*

.PHONY: clean all test

all: $(TARGET) test

$(TARGET): 
	$(CXX) $(CXXFLAGS) $(SRCS_DIR)/$@.cc -o $@ 

test: $(TARGET) 
	@$(TEST_DIR)/run.sh

clean:
	$(RM) $(RM_GC)
	$(RM) $(OBJS)
	$(RM) $(TARGET)
	cd $(SRCS_DIR)      && $(RM) $(RM_GC)
	cd $(TEST_SRCS_DIR) && $(RM) $(RM_GC)

force:

