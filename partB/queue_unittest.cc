#include "gtest/gtest.h"
#include "queue.h"


class QueueTest : public ::testing::Test {
 public:
  void SetUp( ) { 
    // code here will execute just before the test ensues 
    
  }
  void TearDown() {
  }
 protected:

};

TEST_F(QueueTest, QueueConstructorTest) {
  Queue q(5);
  EXPECT_EQ(q.getCapacity(), 5) << "capacity not set up correctly";
  EXPECT_EQ(q.size(), 0) << "size not set up correctly";
  EXPECT_EQ(q.isEmpty(), true) << "isEmpty not set up correctly";
  EXPECT_EQ(q.isFull(), false) << "isFull not set up correctly";
  EXPECT_EQ(q.indexOf(0), -1) << "indexOf not set up correctly";
}

TEST_F(QueueTest, EnqueueTest) {
  Queue q(5);
  q.enqueue(3);
  EXPECT_EQ(q.size(), 1) << "size not set up correctly";
  q.enqueue(7);
  q.enqueue(-5);
  EXPECT_EQ(q.getCapacity(), 5) << "capacity not set up correctly";
  EXPECT_EQ(q.size(), 3) << "size not set up correctly";
  EXPECT_EQ(q.isEmpty(), false) << "isEmpty not set up correctly";
  EXPECT_EQ(q.isFull(), false) << "isFull not set up correctly";
  EXPECT_EQ(q.indexOf(0), -1) << "indexOf not set up correctly";
  EXPECT_EQ(q.indexOf(3), 0) << "indexOf not set up correctly";
  EXPECT_EQ(q.indexOf(7), 1) << "indexOf not set up correctly";
  EXPECT_EQ(q.indexOf(-5), 2) << "indexOf not set up correctly";
  // fill queue and test empty/full
  q.enqueue(4);
  q.enqueue(5);
  EXPECT_EQ(q.isEmpty(), false) << "enqueue/isEmpty not set up correctly";
  EXPECT_EQ(q.isFull(), true) << "enqueue/isFull not set up correctly";
}

TEST_F(QueueTest, PeekTest) {
  // enqueue
  Queue q(5);
  q.enqueue(3);
  EXPECT_EQ(q.peek(), 3) << "peek not set up correctly";
  q.enqueue(7);
  q.enqueue(-5);
  // make sure peek doesn't alter anything
  EXPECT_EQ(q.peek(), 3) << "peek not set up correctly";
  EXPECT_EQ(q.size(), 3) << "peek/size not set up correctly";
  EXPECT_EQ(q.getCapacity(), 5) << "peek/getCapacity not set up correctly";
  EXPECT_EQ(q.indexOf(3), 0) << "peek/indexOf not set up correctly";
  EXPECT_EQ(q.isEmpty(), false) << "peek/isEmpty not set up correctly";
  EXPECT_EQ(q.isFull(), false) << "peek/isFull not set up correctly";
}
TEST_F(QueueTest, DequeueTest) {
  // enqueue
  Queue q(5);
  q.enqueue(3);
  q.enqueue(7);
  q.enqueue(-5);

  // dequeue and test other functions inbetween
  EXPECT_EQ(q.dequeue(), 3) << "dequeue not set up correctly";
  EXPECT_EQ(q.peek(), 7) << "dequeue/peek not set up correctly";
  EXPECT_EQ(q.size(), 2) << "dequeue/size not set up correctly";
  EXPECT_EQ(q.getCapacity(), 5) << "dequeue/getCapacity not set up correctly";
  EXPECT_EQ(q.isEmpty(), false) << "dequeue/isEmpty not set up correctly";
  EXPECT_EQ(q.isFull(), false) << "dequeue/isFull not set up correctly";
  EXPECT_EQ(q.indexOf(3), -1) << "dequeue/indexOf not set up correctly";
  EXPECT_EQ(q.indexOf(7), 0) << "dequeue/indexOf not set up correctly";
  EXPECT_EQ(q.indexOf(-5), 1) << "dequeue/indexOf not set up correctly";

  EXPECT_EQ(q.dequeue(), 7) << "dequeue not set up correctly";
  EXPECT_EQ(q.indexOf(7), -1) << "dequeue/indexOf not set up correctly";
  EXPECT_EQ(q.indexOf(-5), 0) << "dequeue/indexOf not set up correctly";
  EXPECT_EQ(q.peek(), -5) << "dequeue/peek not set up correctly";
  EXPECT_EQ(q.size(), 1) << "dequeue/size not set up correctly";
  
  EXPECT_EQ(q.isEmpty(), false) << "dequeue/isEmpty not set up correctly";
  EXPECT_EQ(q.isFull(), false) << "dequeue/isFull not set up correctly";

  EXPECT_EQ(q.dequeue(), -5) << "dequeue not set up correctly";
  // EXPECT_EQ(q.peek(), NULL) << "dequeue/peek not set up correctly";
  EXPECT_EQ(q.size(), 0) << "dequeue/size not set up correctly";
  EXPECT_EQ(q.indexOf(-5), -1) << "dequeue/indexOf not set up correctly";
  EXPECT_EQ(q.isEmpty(), true) << "dequeue/isEmpty not set up correctly";
  EXPECT_EQ(q.isFull(), false) << "dequeue/isFull not set up correctly";
}



TEST_F(QueueTest, ClearTests) {
  Queue q(5);
  q.enqueue(3);
  EXPECT_EQ(q.indexOf(3), 0) << "clear/indexOf not set up correctly";
  q.enqueue(7);
  EXPECT_EQ(q.indexOf(7), 1) << "clear/indexOf not set up correctly";
  q.enqueue(-5);
  EXPECT_EQ(q.indexOf(-5), 2) << "clear/indexOf not set up correctly";
  q.enqueue(1);
  EXPECT_EQ(q.indexOf(1), 3) << "clear/indexOf not set up correctly";
  q.enqueue(8);
  EXPECT_EQ(q.indexOf(8), 4) << "clear/indexOf not set up correctly";
  EXPECT_EQ(q.size(), 5) << "size not set up correctly";
  EXPECT_EQ(q.isEmpty(), false) << "isEmpty not set up correctly";
  EXPECT_EQ(q.isFull(), true) << "isFull not set up correctly";

  EXPECT_EQ(q.indexOf(3), 0) << "clear/indexOf not set up correctly";
  EXPECT_EQ(q.indexOf(7), 1) << "clear/indexOf not set up correctly";
  EXPECT_EQ(q.indexOf(-5), 2) << "clear/indexOf not set up correctly";
  EXPECT_EQ(q.indexOf(1), 3) << "clear/indexOf not set up correctly";
  EXPECT_EQ(q.indexOf(8), 4) << "clear/indexOf not set up correctly";

  q.clear();
  EXPECT_EQ(q.size(), 0) << "clear/size not set up correctly";
  EXPECT_EQ(q.getCapacity(), 5);
  EXPECT_EQ(q.isEmpty(), true) << "clear/isEmpty not set up correctly";
  EXPECT_EQ(q.isFull(), false) << "clear/isFull not set up correctly";
  EXPECT_EQ(q.indexOf(3), -1) << "clear/indexOf not set up correctly";
  EXPECT_EQ(q.indexOf(7), -1) << "clear/indexOf not set up correctly";
  EXPECT_EQ(q.indexOf(-5), -1) << "clear/indexOf not set up correctly";
  EXPECT_EQ(q.indexOf(1), -1) << "clear/indexOf not set up correctly";
  EXPECT_EQ(q.indexOf(8), -1) << "clear/indexOf not set up correctly";
}

TEST_F(QueueTest, SortTests) {
  Queue q(5);
  int qbyte = sizeof(q);
  // bubble sort
  q.enqueue(0);
  q.enqueue(7);
  q.enqueue(-5);
  q.enqueue(1);
  q.enqueue(8);

  q.bubbleSort();
  EXPECT_EQ(q.size(), 5) << "bubble/size not set up correctly";
  EXPECT_EQ(q.getCapacity(), 5);
  EXPECT_EQ(q.isEmpty(), false) << "bubble/isEmpty not set up correctly";
  EXPECT_EQ(q.isFull(), true) << "bubble/isFull not set up correctly";

  EXPECT_EQ(q.indexOf(-5), 0) << "bubble/indexOf not set up correctly";
  EXPECT_EQ(q.indexOf(0), 1) << "bubble/indexOf not set up correctly";
  EXPECT_EQ(q.indexOf(1), 2) << "bubble/indexOf not set up correctly";
  EXPECT_EQ(q.indexOf(7), 3) << "bubble/indexOf not set up correctly";
  EXPECT_EQ(q.indexOf(8), 4) << "bubble/indexOf not set up correctly";
  EXPECT_EQ(q.indexOf(9), -1) << "bubble/indexOf not set up correctly";
  EXPECT_EQ(q.dequeue(), -5) << "bubble/dequeue not set up correctly";

  q.clear();
  EXPECT_EQ(q.size(), 0) << "clear/size not set up correctly";
  EXPECT_EQ(q.getCapacity(), 5);
  EXPECT_EQ(q.isEmpty(), true) << "clear/isEmpty not set up correctly";
  EXPECT_EQ(q.isFull(), false) << "clear/isFull not set up correctly";
  EXPECT_EQ(sizeof(q), qbyte) << "byte size of q changed";

  // mergesort
  q.enqueue(3);
  q.enqueue(7);
  q.enqueue(-5);
  q.enqueue(1);
  q.enqueue(8);

  q.mergeSort();
  EXPECT_EQ(q.size(), 5) << "merge/size not set up correctly";
  EXPECT_EQ(q.getCapacity(), 5);
  EXPECT_EQ(q.isEmpty(), false) << "merge/isEmpty not set up correctly";
  EXPECT_EQ(q.isFull(), true) << "merge/isFull not set up correctly";

  EXPECT_EQ(q.indexOf(-5), 0) << "merge/indexOf not set up correctly";
  EXPECT_EQ(q.indexOf(1), 1) << "merge/indexOf not set up correctly";
  EXPECT_EQ(q.indexOf(3), 2) << "merge/indexOf not set up correctly";
  EXPECT_EQ(q.indexOf(7), 3) << "merge/indexOf not set up correctly";
  EXPECT_EQ(q.indexOf(8), 4) << "merge/indexOf not set up correctly";

  q.clear();
  EXPECT_EQ(q.getCapacity(), 5);
  EXPECT_EQ(q.size(), 0) << "clear/size not set up correctly";

  q.enqueue(3);
  q.clear();
  EXPECT_EQ(q.getCapacity(), 5);
  EXPECT_EQ(q.size(), 0) << "clear/size not set up correctly";
  

  EXPECT_EQ(sizeof(q), qbyte) << "byte size of q changed";
}

TEST_F(QueueTest, DeathTest) {
  Queue q(5);
  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);
  q.enqueue(4);
  q.enqueue(5);
  EXPECT_DEATH(q.enqueue(6), "") << "attempt to enqueue full queue";
  q.dequeue();
  q.dequeue();
  q.dequeue();
  q.dequeue();
  q.dequeue();
  EXPECT_DEATH(q.dequeue(), "") << "attempt to dequeue empty queue";
  // sort on full/empty queues?
}

TEST_F(QueueTest, CopyConstructorTest) {
  Queue q(5);
  q.enqueue(2);
  q.enqueue(3);
  q.enqueue(1);
  Queue r(q);
  EXPECT_EQ(q.size(), r.size());
  EXPECT_EQ(q.indexOf(2), r.indexOf(2));
  EXPECT_EQ(q.indexOf(3), r.indexOf(3));
  EXPECT_EQ(q.indexOf(1), r.indexOf(1));
  EXPECT_EQ(q.indexOf(3), 1);
  int a = __SIZEOF_POINTER__;
  int b = __SIZEOF_INT__ * 4;
  int size = a + b;
  EXPECT_EQ(sizeof(q), sizeof(r));
  EXPECT_EQ(sizeof(q), size);


  q.dequeue();
  q.dequeue();
  q.enqueue(7);
  r.enqueue(9);

  EXPECT_NE(q.size(), r.size());
  EXPECT_EQ(q.size(), 2);
  EXPECT_EQ(r.size(), 4);
}

TEST_F(QueueTest, SizeTest) {
  Queue q(5);
  int a = __SIZEOF_POINTER__;
  int b = __SIZEOF_INT__ * 4;
  int size = a + b;
  EXPECT_EQ(sizeof(q), size);
}

TEST_F(QueueTest, indexOfTest) {
  Queue q(3);
  EXPECT_EQ(q.indexOf(1), -1);
  q.enqueue(1);
  EXPECT_EQ(q.indexOf(1), 0);
  q.enqueue(1);
  EXPECT_EQ(q.indexOf(1), 0);
}

TEST_F(QueueTest, BubbleSortDequeueTest) {
  Queue q(5);
  q.enqueue(-10);
  q.enqueue(0);
  q.enqueue(-20);
  q.mergeSort();
  EXPECT_EQ(q.indexOf(-20), 0);
  EXPECT_EQ(q.indexOf(0), 2);
  EXPECT_EQ(q.dequeue(), -20);
  q.mergeSort();
  EXPECT_EQ(q.indexOf(-10), 0);
  EXPECT_EQ(q.dequeue(), -10);

}

TEST_F(QueueTest, AssignOperatorTest) {
  Queue q(5);
  q.enqueue(1);
  Queue r = q;

  EXPECT_EQ(r.size(), q.size());
  EXPECT_EQ(r.peek(), q.peek());

  r.dequeue();
  EXPECT_EQ(q.size(), 1);
  EXPECT_EQ(q.peek(), 1);
  EXPECT_EQ(r.size(), 0);

  q.enqueue(2);
  EXPECT_EQ(q.size(), 2);
  EXPECT_EQ(q.peek(), 1);
  EXPECT_EQ(r.size(), 0);

}

TEST_F(QueueTest, AssignOperatorTestTwo) {
  Queue q(10);
  Queue r(5);
  q.enqueue(5);
  r.enqueue(3);
  EXPECT_EQ(r.size(), q.size());
  r = q;
  EXPECT_EQ(r.size(), q.size());
  EXPECT_EQ(q.peek(), r.peek());
  EXPECT_EQ(r.dequeue(), 5);
}

