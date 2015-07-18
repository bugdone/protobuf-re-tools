#include <iostream>
#include <fstream>
#include <string>
#include "reverseme.pb.h"

using namespace std;

int main(int argc, char **argv) {
	com::example::reverseme::SomeData some_data;
	com::example::reverseme::SomeData some_data_bis;
	string serialized;

	GOOGLE_PROTOBUF_VERIFY_VERSION;

	/* Building message */
	cout << "Building message:" << endl;
	com::example::reverseme::SomeData_OtherData* other_data = some_data.mutable_data();
	other_data->set_test(0x1337);
	cout << "SomeData.OtherData.test = " << hex << other_data->test() << endl;
	some_data.set_comment("Yay !");
	cout << "SomeData.comment = " << some_data.comment() << endl;

	/* Serializing */
	cout << "Serializing data ..." << endl;
	some_data.SerializeToString(&serialized);

	/* Deserializing */
	some_data_bis.ParseFromString(serialized);
	cout << "Deserialized message:" << endl;
	cout << "SomeData.OtherData.test = " << hex << some_data.data().test() << endl;
	cout << "SomeData.comment = " << some_data.comment() << endl;

	/* Cleaning */
	google::protobuf::ShutdownProtobufLibrary();

	return 0;
}
