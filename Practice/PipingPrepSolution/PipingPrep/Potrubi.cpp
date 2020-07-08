#include "Potrubi.h"
#include "PrvkyPotrubi.h"

Potrubi::Potrubi(std::istringstream& iss)
{
	char znak;
	iss >> rozmer;
	prvky = new APotrubniPrvek * [rozmer * rozmer];
	APotrubniPrvek* prvek;

	for (int i = 0; i < rozmer; i++)
	{
		iss.get();
		for (int j = 0; j < rozmer; j++)
		{
			iss.get(znak);
			switch (znak) {
			case '-':
				prvek = new PrvekMinus{ j,i };
				break;
			case 'I':
				prvek = new PrvekI{ j,i };
				break;
			case '+':
				prvek = new PrvekPlus{ j,i };
				break;
			case 'T':
				prvek = new PrvekT{ j,i };
				break;
			case 'O':
				prvek = new PrvekO{ j,i };
				break;
			default:
				prvek = nullptr;
				break;
			}
			prvky[i * rozmer + j] = prvek;
		}
	}
}

Potrubi::~Potrubi()
{
	for (int i = 0; i < rozmer; i++)
	{
		delete prvky[i];
	}
	delete[] prvky;
}

APotrubniPrvek* Potrubi::DejPrvek(int x, int y) const
{
	if (x >= 0 && x < rozmer && y >= 0 && y < rozmer)
	{
		return prvky[y * rozmer + x];
	}
	else
		return nullptr;
}

bool Potrubi::JePotrubiOk() const
{
	for (int i = 0; i < rozmer * rozmer; i++)
	{
		if (prvky[i])
			if (!prvky[i]->JeKorektneZapojen(this))
				return false;
	}
	return true;
}
