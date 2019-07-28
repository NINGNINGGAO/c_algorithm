#include <stdio.h>
#include <stdlib.h>
#include "AvlTree.h"
#define Max(a, b) (((a) > (b))?(a):(b))

static int Height(Position P) {
          if (P == NULL) {
                    return -1;
          } else {
                    return P->Height;
          }
}

static Position SingleRotateWithLeft(Position K2) {
          Position K1;

          K1 = K2->Left;
          K2->Left = K1->Right;
          K1->Right = K2;
          if (K2->Left) {
                    K2->Left->Parents = K2;
          }

          K1->Parents = K2->Parents;
          K2->Parents = K1;
          if (K1->Parents) {
                    if (K1->Element > K1->Parents->Element) {
                              K1->Parents->Right = K1;
                    } else {
                              K1->Parents->Left = K1;
                    }
          }

          K2->Height = Max(Height(K2->Left), Height(K2->Right)) + 1;
          K1->Height = Max(Height(K1->Left), Height(K1->Right)) + 1;
          return K1;
}
static Position SingleRotateWithRight(Position K2) {
          Position K1;

          K1 = K2->Right;
          K2->Right = K1->Left;
          K1->Left = K2;
          if (K2->Right) {
                    K2->Right->Parents = K2;
          }
          K1->Parents = K2->Parents;
          K2->Parents = K1;
          if (K1->Parents) {
                    if (K1->Element > K1->Parents->Element) {
                              K1->Parents->Right = K1;
                    } else {
                              K1->Parents->Left = K1;
                    }
          }

          K2->Height = Max(Height(K2->Left), Height(K2->Right)) + 1;
          K1->Height = Max(Height(K1->Left), Height(K1->Right)) + 1;
          return K1;
}

static Position DoubleRotateWithLeft(Position K3) {
          K3->Left = SingleRotateWithRight(K3->Left);
          return SingleRotateWithLeft(K3);
}

static Position  DoubleRotateWithRight(Position K3) {
          K3->Right = SingleRotateWithLeft(K3->Right);
          return SingleRotateWithRight(K3);
}

AvlTree Insert(ElementType X, AvlTree T) {
          Position TmpCell;
          if (X < T->Element) {
                    if (T->Left) {
                              T->Left = Insert(X, T->Left);
                    } else {
                              TmpCell = malloc(sizeof(struct AvlNode));
                              TmpCell->Element = X;
                              TmpCell->Left = NULL;
                              TmpCell->Right = NULL;
                              TmpCell->Height = 0;
                              TmpCell->Parents = T;
                              T->Left = TmpCell;
                    }
                    T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
                    if (Height(T->Left) - Height(T->Right) == 2) {
                              if (X < T->Left->Element) {
                                        T = SingleRotateWithLeft(T);
                              } else {
                                        T = DoubleRotateWithLeft(T);
                              }
                    } 
          } else if (X > T->Element) {
                    if (T->Right) {
                              T->Right = Insert(X, T->Right);
                    } else {
                              TmpCell = malloc(sizeof(struct AvlNode));
                              TmpCell->Element = X;
                              TmpCell->Left = NULL;
                              TmpCell->Right = NULL;
                              TmpCell->Height = 0;
                              TmpCell->Parents = T;
                              T->Right = TmpCell;
                    }
                    T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
                    if (Height(T->Right) - Height(T->Left) == 2) {
                              if (X > T->Right->Element) {
                                        T = SingleRotateWithRight(T);
                              } else {
                                        T = DoubleRotateWithRight(T);
                              }
                    }
          }
          T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
          return T;
}

AvlTree MakeEmpty(AvlTree T) {
          if (T != NULL) {
                    MakeEmpty(T->Left);
                    MakeEmpty(T->Right);
                    free(T);
          }
          return NULL;
}

Position Find(ElementType X, AvlTree T) {
          if (T == NULL) {
                    return NULL;
          }
          if (X < T->Element) {
                    return Find(X, T->Left);
          } else if (X > T->Element) {
                    return Find(X, T->Right);
          } else {
                    return T;
          }
}

Position FindMin(AvlTree T) {
          if (T == NULL) {
                    return NULL;
          } else if (T->Left == NULL) {
                    return T;
          } else {
                    return FindMin(T->Left);
          }          
}

Position FindMax(AvlTree T) {
          if (T != NULL) {
                    while (T->Right != NULL) {
                              T = T->Right;
                    }
          }
          return T;          
}

ElementType Retrieve(Position P) {
          if (P == NULL) {
                    return NULL;
          }
          return P->Element;
}

AvlTree Delete(ElementType X, AvlTree T) {
          Position TmpCell;
          if (T == NULL) {
                    printf("Element not found!!!\n");
          } else if (X < T->Element) {
                    T->Left = Delete(X, T->Left);
                    if (Height(T->Right) - Height(T->Left) == 2) {
                              TmpCell = T->Right;
                              if (Height(T->Right) > Height(T->Left)) {
                                        T = SingleRotateWithRight(T);
                              } else {
                                        T = DoubleRotateWithRight(T);
                              }
                    }
          } else if (X > T->Element) {
                    T->Right = Delete(X, T->Right);
                    if (Height(T->Left) - Height(T->Right) == 2) {
                              TmpCell = T->Left;
                              if (Height(T->Left) > Height(T->Right)) {
                                        T = SingleRotateWithLeft(T);
                              } else {
                                        T = DoubleRotateWithLeft(T);
                              }
                    }
          } else {
                    Position Mid, Temp;
                    if ((T->Left) && (T->Right)) {
                              if (Height(T->Left) > Height(T->Right)) {
                                        Temp = FindMax(T->Left);
                                        Mid = Temp->Parents;
                                        if (Mid != NULL) {
                                                  Mid->Right = Temp->Left;
                                        }
                                        Temp->Left = T->Left;
                                        Temp->Right = T->Right;
                                        Temp->Parents = T->Parents;
                                        if (Temp->Element > Temp->Parents->Element) {
                                                  Temp->Parents->Right = Temp;
                                        } else {
                                                  Temp->Parents->Left = Temp;
                                        }
                                        Temp->Height = Max(Height(Temp->Left), Height(Temp->Right)) + 1;
                                        free(T);
                              } else {
                                        Temp = FindMin(T->Right);
                                        Mid = Temp->Parents;
                                        if (Mid != NULL) {
                                                  Mid->Left = Temp->Right;
                                        }
                                        Temp->Left = T->Left;
                                        Temp->Right = T->Right;
                                        Temp->Parents = T->Parents;    
                                        if (Temp->Element > Temp->Parents->Element) {
                                                  Temp->Parents->Right = Temp;
                                        } else {
                                                  Temp->Parents->Left = Temp;
                                        }                                                                            
                                        Temp->Height = Max(Height(Temp->Left), Height(Temp->Right)) + 1;
                                        free(T);
                                        return Temp;
                              }
                    } else if (T->Left) {
                              Mid = T->Parents;
                              if (Mid != NULL) {
                                        if (T->Element > Mid->Element) {
                                                  Mid->Right = T->Left;
                                        } else {
                                                  Mid->Left = T->Left;
                                        }
                              }
                              T->Left->Parents = Mid;
                              Temp = T->Left;
                              free(T);
                              return Temp;
                    } else if (T->Right) {
                              Mid = T->Parents;
                              if (Mid != NULL) {
                                        if (T->Element > Mid->Element) {
                                                  Mid->Right = T->Right;
                                        } else {
                                                  Mid->Left = T->Right;
                                        }
                              }
                              T->Right->Parents = Mid;
                              Temp = T->Right;
                              free(T);
                              return Temp;
                    } else {
                              Mid = T->Parents;
                              if (Mid != NULL) {
                                        if (T->Element > Mid->Element) {
                                                  Mid->Right = T->Right;
                                        } else {
                                                  Mid->Left = T->Right;
                                        }
                              }
                              free(T);
                              return NULL;
                    }
          }
          return T;
}
