import { View, Text,StyleSheet,StatusBar,
     TextInput,Linking, TouchableOpacity,Image, FlatList,
     } from 'react-native'
import React, { useState,useEffect } from 'react'
import AsyncStorage from '@react-native-async-storage/async-storage'
import ChatHistory from './Components/Chat'
export default function Wha() {
    const [what, setwhat] = useState("")
    const [code, setCode] = useState('91')
    const [chatHistory,setChatHistory] = useState([])
    const [histStats, setHistStats] = useState(false)


    useEffect(() => {
        loadChatHistory();
    }, [])
    useEffect(() => {
        SaveChatHistory();
        
        // console.log("w")
    }, [chatHistory])
    

    const loadChatHistory = async()=>{
        try {
            const hist = await AsyncStorage.getItem('WhatsappHistory');
          if (hist != null) {
            // console.log(hist.length);
            if(hist.length== 2) {
                setHistStats(false);
            }
            else {

                setHistStats(true)
            }
            setChatHistory(JSON.parse(hist));
            // console.log(taskItems);
          }
          else{
            setHistStats(false)
          }
        } catch (error) {
            
        }
    }

    const deleteChatHistory = async(index)=>{
        const temp=[...chatHistory]
        temp.splice(index, 1)
        setChatHistory(temp)
    }

    const SaveChatHistory=async ()=>{
        try {
            const stringifyWhatsappNumber = JSON.stringify(chatHistory);
            if(stringifyWhatsappNumber.length== 2) {
                setHistStats(false);
            }
            else {

                setHistStats(true)
            }
            // console.log(stringifyWhatsappNumber)
            await AsyncStorage.setItem('WhatsappHistory', stringifyWhatsappNumber);
            // console.log('Todo saved successfully')
          } catch (error) {
            console.log(error);
          }
    }

    const chatBtn =async()=>{
        // console.log("Press",what.length)
        var nok=''
        let numbers = '0123456789';
        for (var i=0;i<(what.length);i++){
            if(numbers.indexOf(what[i]) > -1 ){
                nok=nok+what[i]
            }
        }
        var urlofwhats="https://wa.me/"+code+nok
        // console.log(urlofwhats)
        try {
            await Linking.openURL(urlofwhats);
            const dataForHistory ={
                number:what,
                url:urlofwhats
            } 
            const temp=[...chatHistory,dataForHistory]
            setChatHistory(temp)
            setwhat("")
            // Opening the link with some app, if the URL scheme is "http" the web link should be opened
            // by some browser in the mobile
          } catch(e) {
            alert("Something went wrong");
          }
          
        }



        const openHistory = async(WhatsappUrl) =>{
            try {
                await Linking.openURL(WhatsappUrl);
               
                // Opening the link with some app, if the URL scheme is "http" the web link should be opened
                // by some browser in the mobile
              } catch(e) {
                alert("Something went wrong");
              }  
      }


    return (
        <View style={{ flex: 1,marginTop:StatusBar.currentHeight,alignItems: 'center',backgroundColor:'#fff'}}>
            <View style={{ flexDirection: 'row',height:100,marginTop:50,width:"90%",marginHorizontal:'5%' }}>
                <TextInput value={code} 
                 placeholderTextColor={"#c0c0c0"} 
                 placeholder="Code"
                style={[styles.color,styles.codeText]}
                onChangeText={(value)=>{
                    // console.log(value)
                    setCode(value)
                }}
                ></TextInput>
                
                <TextInput  placeholder=' Mobile No without Country Code' placeholderTextColor={"#c0c0c0"} 
                onChangeText={(value)=>{
                    // console.log(value)
                    setwhat(value)
                }}
                value={what}
                style={[styles.color,styles.noText]}
                maxLength={15}
                ></TextInput>
            </View>
            
            <View style={{justifyContent: 'center', alignItems: 'center', alignContent: 'center',height:100 }}>
                {/* <Text style={{ color: 'black', fontSize: 30, marginRight: 20}}>Code</Text> */}
                {/* <TouchableOpacity style={{height:30}} >  */}
                
                <Text onPress={what.length>=10?()=>{
                    // setwhat('');
                    chatBtn()}:null}  
                    style={what.length>=10?[styles.color,styles.chatbtn,{backgroundColor:'#38b000'}] 
                    :[styles.color,styles.chatbtn]}>Chat on Whatsapp</Text>
                {/* </TouchableOpacity> */}
            </View>

            {histStats?
                <View style={styles.history}> 
                    <Text style={styles.chatHist}> Chat History {histStats}</Text>

                    <FlatList
                    data={chatHistory}
                    renderItem={(item, index) => {
                        return (<TouchableOpacity key={index}  onLongPress={()=>{
                            deleteChatHistory(item.index)
                        }} onPress={() => openHistory(item.item.url)}>

                            <ChatHistory text={item.item.number} />
                        </TouchableOpacity>

);
}

}

/>

                </View>
: null}

        </View>
    )
}

const styles = StyleSheet.create({
    chatHist:{
        paddingTop:10,
        fontSize:20,
        color:'black',
        alignSelf:'center',
        fontWeight:'800'
    },
    history: {
        marginTop:20,
        // alignItems: 'center',
        backgroundColor: '#fff',
        height: '100%',
        width:'80%',
        borderRadius:20,
        borderWidth:1,
        elevation:50,
        borderColor:'#c0c0c0'
    },
    color:{
        backgroundColor:'#fff',
        borderRadius:20,
        borderWidth:1,
        borderColor: '#c0c0c0',
        elevation:10,
        marginHorizontal:10
    },
    chatbtn:{
        padding:10,
        borderRadius:15,
        paddingHorizontal:15,
        fontSize:18,
        height:45,
        color:'black',
        fontWeight:'800'
    },
    noText:{
        padding:10,
        height:60,
        width:'68%',
        fontSize:17,
        color:'black',
    },
    codeText:{
        padding:10,
        height:60,
        fontSize:17,
        width:'20%',
        color: "black",
        textAlign:'center'
    }
})