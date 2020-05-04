// ConsoleTest.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>

//----------------实现单例类--------------------
template <class T>
class Single {
public:
    static T* GetInstance() {
        if (T::mObject == nullptr)
        {
            T::mObject = new T();
        }
        return T::mObject;
    }

};

//----------------------------------------
class A {
public:
    static A* mObject;
public:
    void Show() {
        std::cout << "A:" << this << std::endl;
    }
};

A* A::mObject = nullptr;



//画家类
class Painter {
private:

protected:
    void SetShader() {

    }

    void Draw() {
        //使用着色器

        //处理渲染数据等等

        //渲染
    }
};

enum IMAGE_TYPE {
    IMG_
};

class Image : public Painter {
private:
    char file[10][8];
public:
    Image() {
    }
    void Load(const char file[]) {

    }

    void Show(int x,int y) {

        //准备渲染的数据参数

        //调用画家的绘制
        void* Data1 = nullptr;
        void* Data2 = nullptr;
        Draw();
    }
};


int main()
{
    //Single<A>::GetInstance()->Show();
    //Single<A>::GetInstance()->Show();
    //Single<A>::GetInstance()->Show();
    //Single<A>::GetInstance()->Show();

    //对于开发者！

    //显示图片
    Image img;

    //更新
    img.Load("\\data\\1.png");

    //显示
    img.Show(100, 100);

}

