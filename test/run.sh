#!/bin/sh

# 

    TEST_PATH=`dirname $0`
    PROG_DIR=${TEST_PATH}/../
    ASSERT_PREFIX=assert
    SUCCESS_PROMPT='\e[1;32mSUCCESS\e[m'
    FAILURE_PROMPT='\e[1;31mFAILURE\e[m'

# Run all test

    for prog in `find ${PROG_DIR} -maxdepth 1 -type f -perm +111 | sort`
    do
        echo "-- `basename ${prog}` -- "

        PROG_NO=`basename ${prog} | cut -d '_' -f1`
        ASSERT_LIST=`find ${TEST_PATH} -type f -perm +444 -name "${PROG_NO}_*${ASSERT_PREFIX}.txt" | sort`
        for assertfile in ${ASSERT_LIST}
        do
            testfile=${assertfile%_${ASSERT_PREFIX}.txt}.txt
            [[ -f "$testfile" ]] || testfile=""
            $prog $testfile | diff $assertfile - > /dev/null 2>&1

            if [ $? -eq 1 ] ; then
                echo -e "  [${FAILURE_PROMPT}]: ${prog} ${testfile}"
                exit 1
            else
                echo -e "  [${SUCCESS_PROMPT}]: testfile \"${testfile}\""
            fi
        done
    done
