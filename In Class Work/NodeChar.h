#pragma once


struct NodeChar
{
	char data;
	NodeChar* next;
}; 

struct DNodeChar
{
	char data;
	DNodeChar* next;
	DNodeChar* prev;
};