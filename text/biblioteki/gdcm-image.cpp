#include ...

int main() {

    /* Tworzymy obiekt czytającego i wczytujemy plik */
    gdcm::ImageReader ir;
    ir.SetFileName("/path/to/file");
    if (!ir.Read()) {
        /* W przypadku wystąpienia błędu możemy go obsłużyć.
           Klasa gdcm::ImageReader zwróci błąd gdy w pliku nie
           będzie obrazu, bądź będzie w niespieranym formacie */
        return 1;
    }

    /* Pobieramy obiekt obrazu */
    const gdcm::Image &gimage = ir.GetImage();

    /* Tworzymy bufor i zmieniamy jego wielkość. */
    std::vector<char> imgbuffer;
    imgbuffer.resize( gimage.GetBufferLength() );

    /* Pobieramy wymiary obrazu */
    const unsigned int* dimension = gimage.GetDimensions();
    quint dimX = dimension[0];
    quint dimY = dimension[1];

    if (gimage.GetPhotometricInterpretation() == 
        gdcm::PhotometricInterpretation::RGB)
        std::cout << "Jest to obraz RGB" << std::endl;

    if (gimage.GetPhotometricInterpretation() == 
        gdcm::PhotometricInterpretation::MONOCHROME2)  
        std::cout << "Jest to obraz monochromatyczny typu drugiego\n";

    if (gimage.GetPixelFormat() == gdcm::PixelFormat::UINT8)
        std::cout << "Jest to obraz monochromatyczny typu drugiego\n";

    /* Dalej można pobrać plik i zbiór elementów */

    const gdcm::File &file = ir.GetFile();
    const gdcm::DataSet &dataset = ir.GetDataSet();
}