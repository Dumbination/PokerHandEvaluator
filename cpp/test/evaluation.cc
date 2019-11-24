#include <cstdio>
#include <cassert>
#include <algorithm>
#include <phevaluator/phevaluator.h>
#include "gtest/gtest.h"
#include "kev/kev_eval.h"

using namespace phevaluator;

int percentage(long long numerator, long long denominator) {
  return numerator * 100 / denominator;
}

TEST(EvaluationTest, TestFiveCards) {
  int count = 0;
  int progress = 0;
  const int total = 2598960;

  std::printf("Start testing five cards\n");

  for(int a = 0; a < 48; a++)
  {
    for(int b = a + 1; b < 49; b++)
    {
      for(int c = b + 1; c < 50; c++)
      {
        for(int d = c + 1; d < 51; d++)
        {
          for(int e = d + 1; e < 52; e++)
          {
            int ph_eval = EvaluateCards(a, b, c, d, e).value(); // C++ method
            int kev_eval = kev_eval_5cards(a, b, c, d, e); // Kev's method

            assert(ph_eval == kev_eval);

            Hand hand({a, b, c, d, e});
            int ph_hand_eval = EvaluateHand(hand).value();
            assert(ph_hand_eval == kev_eval);

            count++;

            if (percentage(count, total) > progress) {
              progress = percentage(count, total);
              if (progress % 10 == 0) {
                std::printf("Test progress: %d%%\n", progress);
              }
            }
          }
        }
      }
    }
  }

  std::printf("Complete testing five cards.\n");
  std::printf("Tested %d hands in total\n", count);
}

TEST(EvaluationTest, TestSixCards) {
  int count = 0;
  int progress = 0;
  const int total = 20358520;

  std::printf("Start testing six cards\n");

  for(int a = 0; a < 47; a++)
  {
    for(int b = a + 1; b < 48; b++)
    {
      for(int c = b + 1; c < 49; c++)
      {
        for(int d = c + 1; d < 50; d++)
        {
          for(int e = d + 1; e < 51; e++)
          {
            for(int f = e + 1; f < 52; f++)
            {
              int ph_eval = EvaluateCards(a, b, c, d, e, f).value(); // C++ method
              int kev_eval = kev_eval_6cards(a, b, c, d, e, f); // Kev's method

              assert(ph_eval == kev_eval);

              Hand hand({a, b, c, d, e, f});
              int ph_hand_eval = EvaluateHand(hand).value();
              assert(ph_hand_eval == kev_eval);

              count++;

              if (percentage(count, total) > progress) {
                progress = percentage(count, total);
                if (progress % 10 == 0) {
                  std::printf("Test progress: %d%%\n", progress);
                }
              }
            }
          }
        }
      }
    }
  }

  std::printf("Complete testing six cards.\n");
  std::printf("Tested %d hands in total\n", count);
}

TEST(EvaluationTest, TestSevenCards) {
  int count = 0;
  int progress = 0;
  const int total = 133784560;

  std::printf("Start testing seven cards\n");

  for(int a = 0; a < 46; a ++)
  {
    for(int b = a + 1; b < 47; b++)
    {
      for(int c = b + 1; c < 48; c++)
      {
        for(int d = c + 1; d < 49; d++)
        {
          for(int e = d + 1; e < 50; e++)
          {
            for(int f = e + 1; f < 51; f++)
            {
              for(int g = f + 1; g < 52; g++)
              {
                int ph_eval = EvaluateCards(a, b, c, d, e, f, g).value();
                int kev_eval = kev_eval_7cards(a, b, c, d, e, f, g);

                assert(ph_eval == kev_eval);

                Hand hand({a, b, c, d, e, f, g});
                int ph_hand_eval = EvaluateHand(hand).value();
                assert(ph_hand_eval == kev_eval);

                count++;

                if (percentage(count, total) > progress) {
                  progress = percentage(count, total);
                  if (progress % 10 == 0) {
                    std::printf("Test progress: %d%%\n", progress);
                  }
                }
              }
            }
          }
        }
      }
    }
  }

  std::printf("Complete testing seven cards.\n");
  std::printf("Tested %d hands in total\n", count);
}

TEST(EvaluationTest, TestEightCards) {
  int count = 0;
  int progress = 0;
  const int total = 752538150;

  std::printf("Start testing eight cards\n");

  for(int a = 0; a < 45; a ++)
  {
    for(int b = a + 1; b < 46; b++)
    {
      for(int c = b + 1; c < 47; c++)
      {
        for(int d = c + 1; d < 48; d++)
        {
          for(int e = d + 1; e < 49; e++)
          {
            for(int f = e + 1; f < 50; f++)
            {
              for(int g = f + 1; g < 51; g++)
              {
                for(int h = g + 1; h < 52; h++)
                {
                  int ph_eval = EvaluateCards(a, b, c, d, e, f, g, h).value();

                  // Compared with the best hand from 7-card evaluator
                  int best_seven = 10000;

                  best_seven = std::min(best_seven, EvaluateCards(a, b, c, d, e, f, g).value());
                  best_seven = std::min(best_seven, EvaluateCards(a, b, c, d, e, f, h).value());
                  best_seven = std::min(best_seven, EvaluateCards(a, b, c, d, e, h, g).value());
                  best_seven = std::min(best_seven, EvaluateCards(a, b, c, d, h, f, g).value());
                  best_seven = std::min(best_seven, EvaluateCards(a, b, c, h, e, f, g).value());
                  best_seven = std::min(best_seven, EvaluateCards(a, b, h, d, e, f, g).value());
                  best_seven = std::min(best_seven, EvaluateCards(a, h, c, d, e, f, g).value());
                  best_seven = std::min(best_seven, EvaluateCards(h, b, c, d, e, f, g).value());

                  assert(ph_eval == best_seven);

                  Hand hand({a, b, c, d, e, f, g, h});
                  int ph_hand_eval = EvaluateHand(hand).value();
                  assert(ph_hand_eval == kev_eval);

                  count++;

                  if (percentage(count, total) > progress) {
                    progress = percentage(count, total);
                    if (progress % 10 == 0) {
                      std::printf("Test progress: %d%%\n", progress);
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }

  std::printf("Complete testing eight cards.\n");
  std::printf("Tested %d hands in total\n", count);
}

TEST(EvaluationTest, TestNineCards) {
  long long count = 0;
  int progress = 0;
  const long long total = 3679075400;

  std::printf("Start testing nine cards\n");

  for(int a = 0; a < 44; a ++)
  {
    for(int b = a + 1; b < 45; b++)
    {
      for(int c = b + 1; c < 46; c++)
      {
        for(int d = c + 1; d < 47; d++)
        {
          for(int e = d + 1; e < 48; e++)
          {
            for(int f = e + 1; f < 49; f++)
            {
              for(int g = f + 1; g < 50; g++)
              {
                for(int h = g + 1; h < 51; h++)
                {
                  for(int i = h + 1; i < 52; i++)
                  {
                    int ph_eval = EvaluateCards(a, b, c, d, e, f, g, h, i).value();

                    // Compared with the best hand from the 8-card evaluator
                    int best_eight = 10000;

                    best_eight =
                      std::min(best_eight, EvaluateCards(a, b, c, d, e, f, g, h).value());
                    best_eight =
                      std::min(best_eight, EvaluateCards(a, b, c, d, e, f, g, i).value());
                    best_eight =
                      std::min(best_eight, EvaluateCards(a, b, c, d, e, f, i, h).value());
                    best_eight =
                      std::min(best_eight, EvaluateCards(a, b, c, d, e, i, g, h).value());
                    best_eight =
                      std::min(best_eight, EvaluateCards(a, b, c, d, i, f, g, h).value());
                    best_eight =
                      std::min(best_eight, EvaluateCards(a, b, c, i, e, f, g, h).value());
                    best_eight =
                      std::min(best_eight, EvaluateCards(a, b, i, d, e, f, g, h).value());
                    best_eight =
                      std::min(best_eight, EvaluateCards(a, i, c, d, e, f, g, h).value());
                    best_eight =
                      std::min(best_eight, EvaluateCards(i, b, c, d, e, f, g, h).value());

                    assert(ph_eval == best_eight);

                    Hand hand({a, b, c, d, e, f, g, h, i});
                    int ph_hand_eval = EvaluateHand(hand).value();
                    assert(ph_hand_eval == kev_eval);

                    count++;

                    if (percentage(count, total) > progress) {
                      progress = percentage(count, total);
                      if (progress % 10 == 0) {
                        std::printf("Test progress: %d%%\n", progress);
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }

  std::printf("Complete testing nine cards\n");
  std::printf("Tested %lld hands in total\n", count);
}
