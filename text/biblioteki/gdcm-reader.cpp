#include ...

int main() {

    /* Tworzymy obiekt czytającego i wczytujemy plik */
    gdcm::Reader reader;
    reader.SetFileName("/path/to/file");
    if (!reader.Read()) {
        /* W przypadku wystąpienia błędu możemy go obsłużyć */
        return 1;
    }

    /* Pobieramy obiekt pliku */
    const gdcm::File &file = reader.GetFile();

    /* Pobieramy obiekt zbioru danych */
    const gdcm::DataSet &dataset = file.GetDataSet();

    /* Tworzymy pomocniczą klasę do konwertowania danych na std::string */
    gdcm::StringFilter stringFilter;
    stringFilter.SetFile(file);

    /* Tworzymy pomocnicze obiekty znaczników */
    const static gdcm::Tag
            TagPatientName(0x0010, 0x0010),
            TagWindowCenter(0x0028, 0x1050),
            TagWindowWidth(0x0028, 0x1051);

    /* Pobieramy tekst, jeżeli się znajduje w zbiorze */
    if (dataset->FindDataElement(TagPatientName))
        std::string name = stringFilter.GetString(TagPatientName);

    
    if (dataset->FindDataElement(TagWindowCenter)){
        /* Pobieramy element ze zbioru danych */
        const DataElement& ele = dataset->GetDataElement(tag);
        /* Pobieramy 16-bitowego inta */
        quint16 center = ele.GetByteValue()->GetPointer();
    }

    if (dataset->FindDataElement(TagWindowWidth)){
        const DataElement& ele = dataset->GetDataElement(tag);
        quint16 width = ele.GetByteValue()->GetPointer();
    }

}
