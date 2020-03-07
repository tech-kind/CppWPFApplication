#include "stdafx.h"
#include "MainWindowViewModel.h"

using namespace System::Drawing;
using namespace System::Drawing::Imaging;
using namespace System::Windows::Media::Imaging;
using namespace System::IO;
using namespace System;

MainWindowViewModel::MainWindowViewModel() : MainWindowViewModelBase()
{
}

void MainWindowViewModel::ProcessingThreshold()
{
	Bitmap ^bitmap = (Bitmap^)Bitmap::FromFile(DataPath, true);
	float thresh = float::Parse(ThldMax) / 100;

	Color ^color;
	// �w�肳�ꂽ�r�b�g�}�b�v����1dot���̒l���擾���A�擾�����l��臒l�𒴂��Ă��邩�`�F�b�N����
	for (int y = 0; y < bitmap->Size.Height; y++)
	{
		for (int x = 0; x < bitmap->Size.Width; x++)
		{
			color = bitmap->GetPixel(x, y);
			
			float fTemp = color->GetBrightness();
			if (fTemp > thresh)
			{
				bitmap->SetPixel(x, y, Color::White);
			}
			else
			{
				bitmap->SetPixel(x, y, Color::Black);
			}
		}
	}

	MemoryStream ^ms = gcnew MemoryStream();
	bitmap->Save(ms, ImageFormat::Bmp);
	ms->Position = 0;
	BitmapImage ^dst = gcnew BitmapImage();
	dst->BeginInit();
	dst->StreamSource = ms;
	dst->EndInit();
	ProcImage = dst;
}
