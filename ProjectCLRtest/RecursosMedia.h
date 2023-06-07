#pragma once
using namespace System;
using namespace System::Media;
using namespace IO;
using namespace Drawing;
using namespace Resources;
using namespace Reflection;

inline auto CallImage(String^ ArchivoResx, String^ nombre)
{
	Assembly^ pxAssembly = Assembly::GetExecutingAssembly();
	String^ pxResName = pxAssembly->GetName()->Name + "." + ArchivoResx;
	ResourceManager^ pxResourceManager = (gcnew ResourceManager(pxResName, pxAssembly));

	return (cli::safe_cast<Bitmap^>(pxResourceManager->GetObject(nombre)));
}

inline auto CallSound(String^ ArchivoResx, String^ nombre)
{
	Assembly^ pxAssembly = Assembly::GetExecutingAssembly();
	String^ pxResName = pxAssembly->GetName()->Name + "." + ArchivoResx;
	ResourceManager^ pxResourceManager = (gcnew ResourceManager(pxResName, pxAssembly));

	return (cli::safe_cast<Stream^>(pxResourceManager->GetObject(nombre)));
}