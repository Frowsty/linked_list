#include "linked_list.cpp"

#include "gtest/gtest.h"

TEST(Storage,init) {
    Storage *s = new Storage();
    EXPECT_EQ(s->head, nullptr);
}

TEST(Node,init) {
  Node * n = new Node(3);
  EXPECT_EQ(n->data,3);
}

TEST(Storage,push) {
  Storage * s = new Storage();
  s->push(1);
  EXPECT_EQ(s->head->data, 1);
  s->push(2);
  EXPECT_EQ(s->head->data, 2);
  EXPECT_EQ(s->head->next->data, 1);
  s->push(3);
  EXPECT_EQ(s->head->data, 3);
  EXPECT_EQ(s->head->next->data, 2);
  EXPECT_EQ(s->head->next->next->data, 1);
}

TEST(Storage,pop) {
  Storage * s = new Storage();
  int pop;
  s->push(1);
  s->push(2);
  s->push(3);
  EXPECT_TRUE(s->pop(pop));
  EXPECT_EQ(pop, 3);
  EXPECT_TRUE(s->pop(pop));
  EXPECT_EQ(pop, 2);
  EXPECT_TRUE(s->pop(pop));
  EXPECT_EQ(pop, 1);
  EXPECT_FALSE(s->pop(pop));
}

TEST(Storage,peek) {
  Storage * s = new Storage();
  s->push(1);
  int peek;
  EXPECT_TRUE(s->peek(peek));
  EXPECT_EQ(peek,1);
  EXPECT_TRUE(s->peek(peek));
  EXPECT_EQ(peek,1);
  s->push(2);
  EXPECT_TRUE(s->peek(peek));
  EXPECT_EQ(peek,2);
  EXPECT_TRUE(s->peek(peek));
  EXPECT_EQ(peek,2);
  s->push(3);
  EXPECT_TRUE(s->peek(peek));
  EXPECT_EQ(peek,3);
  EXPECT_TRUE(s->peek(peek));
  EXPECT_EQ(peek,3);
}

TEST(Storage,isempty) {
  Storage * s = new Storage();
  int pop;
  EXPECT_TRUE(s->isEmpty());
  s->push(1);
  EXPECT_FALSE(s->isEmpty());
  s->pop(pop);
  EXPECT_TRUE(s->isEmpty());
}

 
TEST(Storage,swap) {
  Storage * s = new Storage();
  EXPECT_FALSE(s->swap(0,1));
  s->push(6);
  s->push(5);
  s->push(4);
  s->push(3);
  s->push(2);
  s->push(1);
  EXPECT_TRUE(s->swap(1,4));
  EXPECT_EQ(s->head->data,1);
  EXPECT_EQ(s->head->next->data, 5);
  EXPECT_EQ(s->head->next->next->data, 3);
  EXPECT_EQ(s->head->next->next->next->data, 4);
  EXPECT_EQ(s->head->next->next->next->next->data, 2);
  EXPECT_EQ(s->head->next->next->next->next->next->data, 6);
  EXPECT_TRUE(s->swap(4,1));
  EXPECT_TRUE(s->swap(4,4));
  EXPECT_EQ(s->head->next->data, 2);
  EXPECT_EQ(s->head->next->next->next->next->data, 5);
  EXPECT_FALSE(s->swap(1,6));
  EXPECT_TRUE(s->swap(0,4));
  EXPECT_EQ(s->head->data, 5);
  EXPECT_EQ(s->head->next->data, 2);
  EXPECT_EQ(s->head->next->next->data, 3);
  EXPECT_EQ(s->head->next->next->next->data, 4);
  EXPECT_EQ(s->head->next->next->next->next->data, 1);
  EXPECT_EQ(s->head->next->next->next->next->next->data, 6);
  EXPECT_TRUE(s->swap(5,0));
  EXPECT_EQ(s->head->data, 6);
  EXPECT_EQ(s->head->next->next->next->next->data, 1);
  EXPECT_EQ(s->head->next->next->next->next->next->data, 5);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
