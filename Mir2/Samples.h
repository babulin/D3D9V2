#pragma once
#include "Log.h"

template<class T>
class ComPtr{
	T object;
public:
	ComPtr() {
	}

	~ComPtr() {
		OutputDebugString(L"~ComPtr\n");
		// Õ∑≈
		delete object;
	}

	T& Get() {
		wchar_t buf[50];
		swprintf_s(buf, TEXT("Get: %p\n"), object);
		OutputDebugString(buf);
		return object;
	}

	T* GetAddress() {
		return &object;
	}

};

class Person {
public:
	Person() {
		wchar_t buf[50];
		swprintf_s(buf, TEXT("Person: %p\n"), this);
		OutputDebugString(buf);
	}
	~Person() {
		wchar_t buf[50];
		swprintf_s(buf, TEXT("~Person: %p\n"), this);
		OutputDebugString(buf);
	}
	void Show() {
		wchar_t buf[50];
		swprintf_s(buf, TEXT("Show: %p\n"), this);
		OutputDebugString(buf);
	}
};






