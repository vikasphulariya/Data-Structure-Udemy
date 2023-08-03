import { View, Text } from 'react-native'
import React from 'react'
import Wha from './Whatsapp/wha'
export default function App() {
  return (
    <View style={{backgroundColor:'#fff',flex:1}}>
      {/* <Text>App</Text> */}
      <Wha/>
    </View>
  )
}