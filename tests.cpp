//yoav1.nach@gmail.com

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "SquareMat.h"
using namespace Matrix;
TEST_CASE("operator mat1 + mat2")
{
    SquareMat s1=SquareMat(2);
    SquareMat s2=SquareMat(2);
    s1[0][0]=1;
    s1[0][1]=2;
    s1[1][0]=3;
    s1[1][1]=4;
    s2[0][0]=5;
    s2[0][1]=6;
    s2[1][0]=7;
    s2[1][1]=8;

    SquareMat res = s1+s2;
    CHECK(res[0][0]==6);
    CHECK(res[0][1]==8);
    CHECK(res[1][0]==10);
    CHECK(res[1][1]==12);

}
TEST_CASE("operator mat1-mat2")
{
    SquareMat s1=SquareMat(2);
    SquareMat s2=SquareMat(2);
    s1[0][0]=1;
    s1[0][1]=2;
    s1[1][0]=3;
    s1[1][1]=4;
    s2[0][0]=5;
    s2[0][1]=6;
    s2[1][0]=7;
    s2[1][1]=8;

    SquareMat res = s1-s2;
    CHECK(res[0][0]==-4);
    CHECK(res[0][1]==-4);
    CHECK(res[1][0]==-4);
    CHECK(res[1][1]==-4);

}
TEST_CASE("operator -mat1")
{
    SquareMat s1=SquareMat(2);
    s1[0][0]=1;
    s1[0][1]=2;
    s1[1][0]=3;
    s1[1][1]=4;
    

    SquareMat res = -s1;
    CHECK(res[0][0]==-1);
    CHECK(res[0][1]==-2);
    CHECK(res[1][0]==-3);
    CHECK(res[1][1]==-4);

}
TEST_CASE("operator mat1*mat2")
{
    SquareMat s1=SquareMat(2);
    SquareMat s2=SquareMat(2);
    s1[0][0]=1;
    s1[0][1]=2;
    s1[1][0]=3;
    s1[1][1]=4;
    s2[0][0]=5;
    s2[0][1]=6;
    s2[1][0]=7;
    s2[1][1]=8;

    SquareMat res = s1*s2;
    CHECK(res[0][0]==19);
    CHECK(res[0][1]==22);
    CHECK(res[1][0]==43);
    CHECK(res[1][1]==50);

}
TEST_CASE("operator mat1=mat2")
{
    SquareMat s1=SquareMat(2);
    SquareMat s2=SquareMat(2);
    s1[0][0]=1;
    s1[0][1]=2;
    s1[1][0]=3;
    s1[1][1]=4;
    s2[0][0]=5;
    s2[0][1]=6;
    s2[1][0]=7;
    s2[1][1]=8;

    s1=s2;
    CHECK(s1[0][0]==5);
    CHECK(s1[0][1]==6);
    CHECK(s1[1][0]==7);
    CHECK(s1[1][1]==8);

}
TEST_CASE("operator mat1*scalar")
{
    SquareMat s1=SquareMat(2);
    int scalar = 5;
    s1[0][0]=1;
    s1[0][1]=2;
    s1[1][0]=3;
    s1[1][1]=4;
    

    SquareMat res = s1*scalar;
    CHECK(res[0][0]==5);
    CHECK(res[0][1]==10);
    CHECK(res[1][0]==15);
    CHECK(res[1][1]==20);

}
TEST_CASE("operator scalar*mat1")
{
    SquareMat s1=SquareMat(2);
    int scalar = -5;
    s1[0][0]=1;
    s1[0][1]=2;
    s1[1][0]=3;
    s1[1][1]=4;
    

    SquareMat res = scalar*s1;
    CHECK(res[0][0]==-5);
    CHECK(res[0][1]==-10);
    CHECK(res[1][0]==-15);
    CHECK(res[1][1]==-20);

}
TEST_CASE("operator mat1%mat2")
{
    SquareMat s1=SquareMat(2);
    SquareMat s2=SquareMat(2);
    s1[0][0]=1;
    s1[0][1]=2;
    s1[1][0]=3;
    s1[1][1]=4;
    s2[0][0]=5;
    s2[0][1]=6;
    s2[1][0]=7;
    s2[1][1]=8;

    SquareMat res = s1%s2;
    CHECK(res[0][0]==5);
    CHECK(res[0][1]==12);
    CHECK(res[1][0]==21);
    CHECK(res[1][1]==32);

}
TEST_CASE("operator mat1 % (scalar)")
{
    SquareMat s1=SquareMat(2);
    int scalar = 2;
    s1[0][0]=1;
    s1[0][1]=2;
    s1[1][0]=3;
    s1[1][1]=4;
    

    SquareMat res = s1%scalar;
    CHECK(res[0][0]==1);
    CHECK(res[0][1]==0);
    CHECK(res[1][0]==1);
    CHECK(res[1][1]==0);

}
TEST_CASE("operator mat1/scalar")
{
    SquareMat s1=SquareMat(2);
    int scalar = 2;
    s1[0][0]=1;
    s1[0][1]=2;
    s1[1][0]=3;
    s1[1][1]=4;
    

    SquareMat res = s1/scalar;
    CHECK(res[0][0]==0.5);
    CHECK(res[0][1]==1);
    CHECK(res[1][0]==1.5);
    CHECK(res[1][1]==2);

}
TEST_CASE("operator mat1^scalar")
{
    SquareMat s1=SquareMat(2);
    int scalar = 3;
    s1[0][0]=1;
    s1[0][1]=2;
    s1[1][0]=3;
    s1[1][1]=4;
    

    SquareMat res = s1^scalar;
    CHECK(res[0][0]==37);
    CHECK(res[0][1]==54);
    CHECK(res[1][0]==81);
    CHECK(res[1][1]==118);

}
TEST_CASE("operator mat1[]")
{
    SquareMat s1=SquareMat(2);
    s1[0][0]=1;
    s1[0][1]=2;
    s1[1][0]=3;
    s1[1][1]=4;
    

    double* res = s1[0];
    CHECK(res[0]==1);
    CHECK(res[1]==2);
    double res2 = s1[0][1];
    CHECK(res2==2);
}
TEST_CASE("operator mat1++")
{
    SquareMat s1=SquareMat(2);
    s1[0][0]=1;
    s1[0][1]=2;
    s1[1][0]=3;
    s1[1][1]=4;
    

    CHECK(s1++[0][0]==1);
    CHECK(s1[0][0]==2);
    
}
TEST_CASE("operator ++mat1")
{
    SquareMat s1=SquareMat(2);
    s1[0][0]=1;
    s1[0][1]=2;
    s1[1][0]=3;
    s1[1][1]=4;
    

    CHECK(++s1[0][0]==2);
    CHECK(s1[0][0]==2);
    
}
TEST_CASE("operator ~mat1")
{
    SquareMat s1=SquareMat(2);
    s1[0][0]=1;
    s1[0][1]=2;
    s1[1][0]=3;
    s1[1][1]=4;
    
    ~s1;
    CHECK(s1[0][0]==1);
    CHECK(s1[0][1]==3);
    CHECK(s1[1][0]==2);
    CHECK(s1[1][1]==4);
    
}
TEST_CASE("operator mat1==mat2")
{
    SquareMat s1=SquareMat(2);
    SquareMat s2=SquareMat(2);
    s1[0][0]=1;
    s1[0][1]=2;
    s1[1][0]=3;
    s1[1][1]=4;
    s2[0][0]=5;
    s2[0][1]=6;
    s2[1][0]=7;
    s2[1][1]=8;

    bool res = s1==s2;
    CHECK(!res);

    s2[0][0]=4;
    s2[0][1]=3;
    s2[1][0]=2;
    s2[1][1]=1;

    res = s1==s2;
    CHECK(res);

}
TEST_CASE("operator mat1!=mat2")
{
    SquareMat s1=SquareMat(2);
    SquareMat s2=SquareMat(2);
    s1[0][0]=1;
    s1[0][1]=2;
    s1[1][0]=3;
    s1[1][1]=4;
    s2[0][0]=5;
    s2[0][1]=6;
    s2[1][0]=7;
    s2[1][1]=8;

    bool res = s1!=s2;
    CHECK(res);

    s2[0][0]=4;
    s2[0][1]=3;
    s2[1][0]=2;
    s2[1][1]=1;

    res = s1!=s2;
    CHECK(!res);

}
TEST_CASE("operator mat1<mat2")
{
    SquareMat s1=SquareMat(2);
    SquareMat s2=SquareMat(2);
    s1[0][0]=1;
    s1[0][1]=2;
    s1[1][0]=3;
    s1[1][1]=4;
    s2[0][0]=5;
    s2[0][1]=6;
    s2[1][0]=7;
    s2[1][1]=8;

    bool res = s1<s2;
    CHECK(res);

    s2[0][0]=-67;
    s2[0][1]=3;
    s2[1][0]=2;
    s2[1][1]=1;

    res = s1<s2;
    CHECK(!res);

}
TEST_CASE("operator mat1>mat2")
{
    SquareMat s1=SquareMat(2);
    SquareMat s2=SquareMat(2);
    s1[0][0]=1;
    s1[0][1]=2;
    s1[1][0]=3;
    s1[1][1]=4;
    s2[0][0]=5;
    s2[0][1]=6;
    s2[1][0]=7;
    s2[1][1]=8;

    bool res = s1>s2;
    CHECK(!res);

    s2[0][0]=-67;
    s2[0][1]=3;
    s2[1][0]=2;
    s2[1][1]=1;

    res = s1>s2;
    CHECK(res);

}
TEST_CASE("operator mat1<=mat2")
{
    SquareMat s1=SquareMat(2);
    SquareMat s2=SquareMat(2);
    s1[0][0]=1;
    s1[0][1]=2;
    s1[1][0]=3;
    s1[1][1]=4;
    s2[0][0]=5;
    s2[0][1]=6;
    s2[1][0]=7;
    s2[1][1]=8;

    bool res = s1<=s2;
    CHECK(res);

    s2[0][0]=-67;
    s2[0][1]=3;
    s2[1][0]=2;
    s2[1][1]=1;

    res = s1<=s2;
    CHECK(!res);

    s2[0][0]=4;
    s2[0][1]=3;
    s2[1][0]=2;
    s2[1][1]=1;

    res = s1<=s2;
    CHECK(res);

}
TEST_CASE("operator mat1>=mat2")
{
    SquareMat s1=SquareMat(2);
    SquareMat s2=SquareMat(2);
    s1[0][0]=1;
    s1[0][1]=2;
    s1[1][0]=3;
    s1[1][1]=4;
    s2[0][0]=5;
    s2[0][1]=6;
    s2[1][0]=7;
    s2[1][1]=8;

    bool res = s1>=s2;
    CHECK(!res);

    s2[0][0]=-67;
    s2[0][1]=3;
    s2[1][0]=2;
    s2[1][1]=1;

    res = s1>=s2;
    CHECK(res);

    s2[0][0]=4;
    s2[0][1]=3;
    s2[1][0]=2;
    s2[1][1]=1;

    res = s1>=s2;
    CHECK(res);

}

TEST_CASE("operator !mat1")
{
    SquareMat s1=SquareMat(2);
    s1[0][0]=1;
    s1[0][1]=2;
    s1[1][0]=3;
    s1[1][1]=4;
    
    double res=!s1;
    CHECK(res==-2);
    
}
TEST_CASE("operator mat1+=mat2")
{
    SquareMat s1=SquareMat(2);
    SquareMat s2=SquareMat(2);
    s1[0][0]=1;
    s1[0][1]=2;
    s1[1][0]=3;
    s1[1][1]=4;
    s2[0][0]=5;
    s2[0][1]=6;
    s2[1][0]=7;
    s2[1][1]=8;

    s1+=s2;
    CHECK(s1[0][0]==6);
    CHECK(s1[0][1]==8);
    CHECK(s1[1][0]==10);
    CHECK(s1[1][1]==12);

}
TEST_CASE("operator mat1-=mat2")
{
    SquareMat s1=SquareMat(2);
    SquareMat s2=SquareMat(2);
    s1[0][0]=1;
    s1[0][1]=2;
    s1[1][0]=3;
    s1[1][1]=4;
    s2[0][0]=5;
    s2[0][1]=6;
    s2[1][0]=7;
    s2[1][1]=8;

    s1-=s2;
    CHECK(s1[0][0]==-4);
    CHECK(s1[0][1]==-4);
    CHECK(s1[1][0]==-4);
    CHECK(s1[1][1]==-4);

}
TEST_CASE("operator mat1*=scalar")
{
    SquareMat s1=SquareMat(2);
    s1[0][0]=1;
    s1[0][1]=2;
    s1[1][0]=3;
    s1[1][1]=4;
    double scalar=5;
    s1*=scalar;
    CHECK(s1[0][0]==5);
    CHECK(s1[0][1]==10);
    CHECK(s1[1][0]==15);
    CHECK(s1[1][1]==20);

}
TEST_CASE("operator mat1*=mat2")
{
    SquareMat s1=SquareMat(2);
    SquareMat s2=SquareMat(2);
    s1[0][0]=1;
    s1[0][1]=2;
    s1[1][0]=3;
    s1[1][1]=4;
    s2[0][0]=5;
    s2[0][1]=6;
    s2[1][0]=7;
    s2[1][1]=8;

    s1*=s2;
    CHECK(s1[0][0]==19);
    CHECK(s1[0][1]==22);
    CHECK(s1[1][0]==43);
    CHECK(s1[1][1]==50);

}

TEST_CASE("operator mat1%=mat2")
{
    SquareMat s1=SquareMat(2);
    SquareMat s2=SquareMat(2);
    s1[0][0]=1;
    s1[0][1]=2;
    s1[1][0]=3;
    s1[1][1]=4;
    s2[0][0]=5;
    s2[0][1]=6;
    s2[1][0]=7;
    s2[1][1]=8;

    s1%=s2;
    CHECK(s1[0][0]==5);
    CHECK(s1[0][1]==12);
    CHECK(s1[1][0]==21);
    CHECK(s1[1][1]==32);

}

TEST_CASE("operator mat1%=scalar")
{
    SquareMat s1=SquareMat(2);
    s1[0][0]=1;
    s1[0][1]=2;
    s1[1][0]=3;
    s1[1][1]=4;
    double scalar=2;
    s1%=scalar;
    CHECK(s1[0][0]==1);
    CHECK(s1[0][1]==0);
    CHECK(s1[1][0]==1);
    CHECK(s1[1][1]==0);

}
TEST_CASE("operator mat1/=scalar")
{
    SquareMat s1=SquareMat(2);
    s1[0][0]=1;
    s1[0][1]=2;
    s1[1][0]=3;
    s1[1][1]=4;
    double scalar=2;
    s1/=scalar;
    CHECK(s1[0][0]==0.5);
    CHECK(s1[0][1]==1);
    CHECK(s1[1][0]==1.5);
    CHECK(s1[1][1]==2);

}

